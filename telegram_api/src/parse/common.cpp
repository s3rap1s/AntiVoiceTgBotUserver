#include <parse/common.hpp>

#include <types/common.hpp>

#include <userver/formats/json/value.hpp>
#include <userver/formats/parse/to.hpp>

namespace tg {

namespace detail {

template <typename T>
struct is_vector : std::false_type {};

template <typename T, typename Alloc>
struct is_vector<std::vector<T, Alloc>> : std::true_type {};

template <typename T>
inline constexpr bool is_vector_v = is_vector<T>::value;

inline bool IsPresent(const userver::formats::json::Value& v) {
    return !v.IsMissing() && !v.IsNull();
}

}  // namespace detail

template <typename T>
T ParseComplex(const userver::formats::json::Value& v) {
    return v.As<T>();
}

template <typename T>
Array<T> ParseArray(const userver::formats::json::Value& v) {
    Array<T> out;
    out.reserve(v.GetSize());
    for (const auto& item : v) {
        out.push_back(ParseComplex<T>(item));
    }
    return out;
}

template <typename T>
Optional<T> ParseOptional(const userver::formats::json::Value& v) {
    if (!detail::IsPresent(v)) {
        return std::nullopt;
    }

    if constexpr (detail::is_vector_v<T>) {
        using Item = typename T::value_type;
        return ParseArray<Item>(v);
    } else {
        return ParseComplex<T>(v);
    }
}

template <typename T>
Ptr<T> ParsePtr(const userver::formats::json::Value& v) {
    if (!detail::IsPresent(v)) {
        return nullptr;
    }
    return std::make_unique<T>(ParseComplex<T>(v));
}

inline OptionalTrue ParseOptionalTrue(const userver::formats::json::Value& v) {
    if (!detail::IsPresent(v)) {
        return std::nullopt;
    }

    const auto value = v.As<bool>();
    if (!value) {
        throw std::runtime_error(
            "Telegram OptionalTrue field is present but false");
    }

    return std::monostate{};
}

}  // namespace tg