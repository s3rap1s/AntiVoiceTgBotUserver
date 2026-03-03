#pragma once

#include <memory>
#include <optional>
#include <type_traits>
#include <variant>
#include <vector>

#include <tg/types/common.hpp>

namespace tg::internal {

template <typename T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

template <typename T>
inline constexpr bool is_json_v = std::is_same_v<remove_cvref_t<T>, userver::formats::json::Value>;

template <typename T>
inline constexpr bool is_trivial_json_type_v =
    std::is_same_v<std::remove_cv_t<T>, bool> || std::is_integral_v<std::remove_cv_t<T>> ||
    std::is_floating_point_v<std::remove_cv_t<T>> || std::is_same_v<std::remove_cv_t<T>, std::string>;

// optional
template <typename T>
struct is_optional : std::false_type {};
template <typename U>
struct is_optional<std::optional<U>> : std::true_type {};
template <typename T>
inline constexpr bool is_optional_v = is_optional<std::remove_cv_t<T>>::value;
template <typename T>
inline constexpr bool is_optional_true_v = std::is_same_v<T, OptionalTrue>;

template <typename T>
struct optional_inner;
template <typename U>
struct optional_inner<std::optional<U>> {
    using type = U;
};
template <typename T>
using optional_inner_t = typename optional_inner<std::remove_cv_t<T>>::type;

// vector
template <typename T>
struct is_vector : std::false_type {};
template <typename U, typename Alloc>
struct is_vector<std::vector<U, Alloc>> : std::true_type {};
template <typename T>
inline constexpr bool is_vector_v = is_vector<std::remove_cv_t<T>>::value;

template <typename T>
struct vector_inner;
template <typename U, typename Alloc>
struct vector_inner<std::vector<U, Alloc>> {
    using type = U;
};
template <typename T>
using vector_inner_t = typename vector_inner<std::remove_cv_t<T>>::type;

// unique_ptr
template <typename T>
struct is_unique_ptr : std::false_type {};
template <typename U, typename D>
struct is_unique_ptr<std::unique_ptr<U, D>> : std::true_type {};
template <typename T>
inline constexpr bool is_unique_ptr_v = is_unique_ptr<std::remove_cv_t<T>>::value;

template <typename T>
struct unique_ptr_inner;
template <typename U, typename D>
struct unique_ptr_inner<std::unique_ptr<U, D>> {
    using type = U;
};
template <typename T>
using unique_ptr_inner_t = typename unique_ptr_inner<std::remove_cv_t<T>>::type;

// variant
template <typename T>
struct is_variant : std::false_type {};
template <typename... Ts>
struct is_variant<std::variant<Ts...>> : std::true_type {};
template <typename T>
inline constexpr bool is_variant_v = is_variant<std::remove_cv_t<T>>::value;
template <typename T>
struct is_trivial_variant : std::false_type {};
template <typename... Ts>
struct is_trivial_variant<std::variant<Ts...>> : std::bool_constant<(is_trivial_json_type_v<Ts> && ...)> {};
template <typename T>
inline constexpr bool is_trivial_variant_v = is_trivial_variant<T>::value;

}  // namespace tg::internal