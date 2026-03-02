#pragma once

#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

#include <userver/formats/json/value.hpp>
#include <userver/formats/parse/to.hpp>

#include <types/common.hpp>

namespace tg {

using Value = userver::formats::json::Value;

template <typename T>
using To = userver::formats::parse::To<T>;

template <typename T>
T ParseComplex(const Value& v);

namespace detail {
// check field presense
inline bool IsPresent(const Value& v) { return !v.IsMissing() && !v.IsNull(); }

// check vector type
template <typename T>
struct is_vector : std::false_type {};
template <typename T, typename Alloc>
struct is_vector<std::vector<T, Alloc>> : std::true_type {};
template <typename T>
inline constexpr bool is_vector_v = is_vector<T>::value;

// check optional type
template <typename T>
struct is_optional : std::false_type {};
template <typename U>
struct is_optional<std::optional<U>> : std::true_type {};
template <typename T>
inline constexpr bool is_optional_v = is_optional<T>::value;

template <typename T>
struct optional_inner;
template <typename U>
struct optional_inner<std::optional<U>> {
    using type = U;
};
template <typename T>
using optional_inner_t = typename optional_inner<T>::type;

template <typename T>
struct is_unique_ptr : std::false_type {};
template <typename U, typename D>
struct is_unique_ptr<std::unique_ptr<U, D>> : std::true_type {};
template <typename T>
inline constexpr bool is_unique_ptr_v = is_unique_ptr<T>::value;

template <typename T>
struct unique_ptr_inner;
template <typename U, typename D>
struct unique_ptr_inner<std::unique_ptr<U, D>> {
    using type = U;
};
template <typename T>
using unique_ptr_inner_t = typename unique_ptr_inner<T>::type;

template <typename T>
inline constexpr bool is_optional_true_v = std::is_same_v<T, OptionalTrue>;

template <typename T>
struct is_variant : std::false_type {};
template <typename... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {};
template <typename T>
inline constexpr bool is_variant_v = is_variant<T>::value;

// “Trivial JSON types”: numbers/bool/string
template <typename T>
inline constexpr bool is_trivial_json_type_v =
    std::is_same_v<std::remove_cv_t<T>, bool> ||
    std::is_integral_v<std::remove_cv_t<T>> ||
    std::is_floating_point_v<std::remove_cv_t<T>> ||
    std::is_same_v<std::remove_cv_t<T>, std::string>;

// Variant is “trivial” only if ALL alternatives are trivial json types
template <typename T>
struct is_trivial_variant : std::false_type {};
template <typename... Ts>
struct is_trivial_variant<std::variant<Ts...>>
    : std::bool_constant<(is_trivial_json_type_v<Ts> && ...)> {};
template <typename T>
inline constexpr bool is_trivial_variant_v = is_trivial_variant<T>::value;

// Runtime matcher for trivial alternative
template <typename T>
bool MatchesJsonType(const Value& v) {
    using U = std::remove_cv_t<T>;

    if constexpr (std::is_same_v<U, std::string>) {
        return v.IsString();
    } else if constexpr (std::is_same_v<U, bool>) {
        return v.IsBool();
    } else if constexpr (std::is_integral_v<U>) {
        return v.IsInt64() || v.IsUInt64();
    } else if constexpr (std::is_floating_point_v<U>) {
        return v.IsDouble() || v.IsInt64() || v.IsUInt64();
    } else {
        return false;
    }
}

template <typename Variant, std::size_t I = 0>
Variant ParseTrivialVariant(const Value& v) {
    if constexpr (I >= std::variant_size_v<Variant>) {
        throw std::runtime_error(
            "No matching trivial variant alternative for JSON value");
    } else {
        using Alt = std::variant_alternative_t<I, Variant>;
        if (MatchesJsonType<Alt>(v)) {
            return Variant{std::in_place_type<Alt>, ParseComplex<Alt>(v)};
        }
        return ParseTrivialVariant<Variant, I + 1>(v);
    }
}

}  // namespace detail

template <typename T>
Array<T> ParseArray(const Value& v) {
    Array<T> out;
    out.reserve(v.GetSize());
    for (const auto& item : v) out.push_back(ParseComplex<T>(item));
    return out;
}

template <typename T>
Optional<T> ParseOptional(const Value& v) {
    if (!detail::IsPresent(v)) return std::nullopt;

    if constexpr (detail::is_vector_v<T>) {
        using Item = typename T::value_type;
        return ParseArray<Item>(v);
    } else {
        return ParseComplex<T>(v);
    }
}

template <typename UPtr>
UPtr ParseUniquePtr(const Value& v) {
    if (!detail::IsPresent(v)) return UPtr{};
    using U = typename UPtr::element_type;
    U obj = ParseComplex<U>(v);
    return UPtr{new U(std::move(obj))};
}

inline OptionalTrue ParseOptionalTrue(const Value& v) {
    if (!detail::IsPresent(v)) return std::nullopt;
    const bool b = v.As<bool>();
    if (!b) throw std::runtime_error("OptionalTrue present but false");
    return std::monostate{};
}

template <typename T>
T ParseComplex(const Value& v) {
    if constexpr (detail::is_optional_true_v<T>) {
        return ParseOptionalTrue(v);

    } else if constexpr (detail::is_optional_v<T>) {
        using U = detail::optional_inner_t<T>;
        return ParseOptional<U>(v);

    } else if constexpr (detail::is_unique_ptr_v<T>) {
        return ParseUniquePtr<T>(v);

    } else if constexpr (detail::is_vector_v<T>) {
        using U = typename T::value_type;
        return ParseArray<U>(v);

    } else if constexpr (detail::is_variant_v<T>) {
        if constexpr (detail::is_trivial_variant_v<T>) {
            return detail::ParseTrivialVariant<T>(v);
        } else {
            return tg::Parse(v, To<T>{});
        }

    } else {
        return v.As<T>();
    }
}

}  // namespace tg