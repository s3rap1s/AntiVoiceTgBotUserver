#pragma once

#include <memory>
#include <optional>
#include <type_traits>
#include <variant>
#include <vector>

#include <tg/types/common.hpp>

namespace tg::internal {

template <typename T>
using normalized_t = std::remove_cvref_t<T>;

template <typename>
inline constexpr bool always_false_v = false;

template <typename T>
inline constexpr bool is_json_v = std::is_same_v<normalized_t<T>, userver::formats::json::Value>;

template <typename T>
inline constexpr bool is_trivial_json_type_v =
    std::is_same_v<normalized_t<T>, bool> || std::is_integral_v<normalized_t<T>> ||
    std::is_floating_point_v<normalized_t<T>> || std::is_same_v<normalized_t<T>, std::string>;

// optional-like
template <typename T>
struct is_optional : std::false_type {};
template <typename U>
struct is_optional<std::optional<U>> : std::true_type {};
template <typename T>
inline constexpr bool is_optional_v = is_optional<normalized_t<T>>::value;
template <typename T>
inline constexpr bool is_optional_true_v = std::is_same_v<T, OptionalTrue>;

template <typename T>
struct optional_inner;
template <typename U>
struct optional_inner<std::optional<U>> {
    using type = U;
};
template <typename T>
using optional_inner_t = typename optional_inner<normalized_t<T>>::type;

template <typename T>
concept OptionalLike = is_optional_v<T>;

// vector-like
template <typename T>
struct is_vector : std::false_type {};
template <typename U, typename Alloc>
struct is_vector<std::vector<U, Alloc>> : std::true_type {};
template <typename T>
inline constexpr bool is_vector_v = is_vector<normalized_t<T>>::value;

template <typename T>
struct vector_inner;
template <typename U, typename Alloc>
struct vector_inner<std::vector<U, Alloc>> {
    using type = U;
};
template <typename T>
using vector_inner_t = typename vector_inner<normalized_t<T>>::type;

template <typename T>
concept VectorLike = is_vector_v<T>;

// unique_ptr-like
template <typename T>
struct is_unique_ptr : std::false_type {};
template <typename U, typename D>
struct is_unique_ptr<std::unique_ptr<U, D>> : std::true_type {};
template <typename T>
inline constexpr bool is_unique_ptr_v = is_unique_ptr<normalized_t<T>>::value;

template <typename T>
struct unique_ptr_inner;
template <typename U, typename D>
struct unique_ptr_inner<std::unique_ptr<U, D>> {
    using type = U;
};
template <typename T>
using unique_ptr_inner_t = typename unique_ptr_inner<normalized_t<T>>::type;

template <typename T>
concept UniquePtrLike = is_unique_ptr_v<T>;

// variant-like
template <typename T>
struct is_variant : std::false_type {};
template <typename... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {};
template <typename T>
inline constexpr bool is_variant_v = is_variant<normalized_t<T>>::value;

template <typename T>
struct is_trivial_variant : std::false_type {};
template <typename... Ts>
struct is_trivial_variant<std::variant<Ts...>> : std::bool_constant<(is_trivial_json_type_v<Ts> && ...)> {};
template <typename T>
inline constexpr bool is_trivial_variant_v = is_trivial_variant<normalized_t<T>>::value;

template <typename T>
concept VariantLike = is_variant_v<T>;

}  // namespace tg::internal
