#pragma once

#include <optional>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <userver/formats/json/value.hpp>
#include <userver/formats/json/value_builder.hpp>
#include <userver/formats/parse/to.hpp>
#include <variant>

#include <tg/types/common.hpp>

#include "../internal/type_traits.hpp"

namespace tg {

using Value = userver::formats::json::Value;

template <typename T>
using To = userver::formats::parse::To<T>;

template <typename T>
T ParseComplex(const Value& value);

namespace internal {
// check field presense
inline bool IsPresent(const Value& value) { return !value.IsMissing() && !value.IsNull(); }

template <typename T>
bool MatchesJsonType(const Value& value) {
    using U = std::remove_cv_t<T>;

    if constexpr (std::is_same_v<U, std::string>) {
        return value.IsString();
    } else if constexpr (std::is_same_v<U, bool>) {
        return value.IsBool();
    } else if constexpr (std::is_integral_v<U>) {
        return value.IsInt64() || value.IsUInt64();
    } else if constexpr (std::is_floating_point_v<U>) {
        return value.IsDouble() || value.IsInt64() || value.IsUInt64();
    } else {
        return false;
    }
}

template <typename Variant, std::size_t I = 0>
Variant ParseTrivialVariant(const Value& value) {
    if constexpr (I >= std::variant_size_v<Variant>) {
        throw std::runtime_error("No matching trivial variant alternative for JSON value");
    } else {
        using Alt = std::variant_alternative_t<I, Variant>;
        if (MatchesJsonType<Alt>(value)) {
            return Variant{std::in_place_type<Alt>, ParseComplex<Alt>(value)};
        }
        return ParseTrivialVariant<Variant, I + 1>(value);
    }
}

}  // namespace internal

template <typename T>
Array<T> ParseArray(const Value& value) {
    Array<T> out;
    out.reserve(value.GetSize());
    for (const auto& item : value) out.push_back(ParseComplex<T>(item));
    return out;
}

template <typename T>
Optional<T> ParseOptional(const Value& value) {
    if (!internal::IsPresent(value)) return std::nullopt;

    if constexpr (internal::is_vector_v<T>) {
        using Item = typename T::value_type;
        return ParseArray<Item>(value);
    } else {
        return ParseComplex<T>(value);
    }
}

template <typename UPtr>
UPtr ParseUniquePtr(const Value& value) {
    if (!internal::IsPresent(value)) return UPtr{};
    using U = typename UPtr::element_type;
    U obj = ParseComplex<U>(value);
    return UPtr{new U(std::move(obj))};
}

inline OptionalTrue ParseOptionalTrue(const Value& value) {
    if (!internal::IsPresent(value)) return std::nullopt;
    const bool b = value.As<bool>();
    if (!b) throw std::runtime_error("OptionalTrue present but false");
    return std::monostate{};
}

template <typename T>
T ParseComplex(const Value& value) {
    if constexpr (internal::is_optional_true_v<T>) {
        return ParseOptionalTrue(value);

    } else if constexpr (internal::is_optional_v<T>) {
        using U = internal::optional_inner_t<T>;
        return ParseOptional<U>(value);

    } else if constexpr (internal::is_unique_ptr_v<T>) {
        return ParseUniquePtr<T>(value);

    } else if constexpr (internal::is_vector_v<T>) {
        using U = typename T::value_type;
        return ParseArray<U>(value);

    } else if constexpr (internal::is_variant_v<T>) {
        if constexpr (internal::is_trivial_variant_v<T>) {
            return internal::ParseTrivialVariant<T>(value);
        } else {
            return Parse(value, To<T>{});
        }

    } else {
        return value.As<T>();
    }
}

}  // namespace tg