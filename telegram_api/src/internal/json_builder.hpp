#pragma once

#include <string>
#include <string_view>
#include <variant>

#include <userver/formats/common/type.hpp>
#include <userver/formats/json/value.hpp>
#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

#include "type_traits.hpp"

namespace tg::internal {

using Json = userver::formats::json::Value;
using ValueBuilder = userver::formats::json::ValueBuilder;
using Type = userver::formats::common::Type;

inline std::string to_string(std::string_view sv) { return std::string{sv}; }

template <typename T>
concept HasSerialize = requires(const T& object, ValueBuilder& builder) { Serialize(object, builder); };

inline ValueBuilder MakeObject() { return ValueBuilder(Type::kObject); }
inline ValueBuilder MakeArray() { return ValueBuilder(Type::kArray); }

// add as value
inline void Set(ValueBuilder& builder, const Json& value) { builder = value; }
inline void Set(ValueBuilder& builder, Json&& value) { builder = std::move(value); }

// trivial types
inline void Set(ValueBuilder& builder, const String& value) { builder = value; }
inline void Set(ValueBuilder& builder, std::string_view value) { builder = std::string{value}; }
inline void Set(ValueBuilder& builder, Boolean value) { builder = value; }
inline void Set(ValueBuilder& builder, Float value) { builder = value; }
inline void Set(ValueBuilder& builder, Integer value) { builder = value; }

template <typename T>
inline void Set(ValueBuilder& builder, const T& value) {
    using U = tg::internal::normalized_t<T>;

    if constexpr (tg::internal::is_optional_true_v<U>) {
        if (value)
            builder = true;
        else
            builder = ValueBuilder();  // null

    } else if constexpr (tg::internal::OptionalLike<U>) {
        if (!value) {
            builder = ValueBuilder();  // null
            return;
        }
        using Inner = tg::internal::optional_inner_t<U>;
        Set(builder, static_cast<const Inner&>(*value));

    } else if constexpr (tg::internal::UniquePtrLike<U>) {
        if (!value) {
            builder = ValueBuilder();  // null
            return;
        }
        using Inner = tg::internal::unique_ptr_inner_t<U>;
        Set(builder, static_cast<const Inner&>(*value));

    } else if constexpr (tg::internal::VectorLike<U>) {
        using Item = tg::internal::vector_inner_t<U>;
        ValueBuilder array_builder(Type::kArray);
        for (const auto& item : value) {
            ValueBuilder element_builder;
            Set(element_builder, static_cast<const Item&>(item));
            array_builder.PushBack(element_builder.ExtractValue());
        }
        builder = array_builder.ExtractValue();

    } else if constexpr (tg::internal::VariantLike<U>) {
        std::visit([&](const auto& x) { Set(builder, x); }, value);

    } else if constexpr (HasSerialize<U>) {
        ValueBuilder object_builder(Type::kObject);
        Serialize(value, object_builder);
        builder = object_builder.ExtractValue();
    } else {
        static_assert(tg::internal::always_false_v<U>, "Unsupported type for tg::internal::Set");
    }
}

template <typename T>
inline Json ToJsonValue(const T& value) {
    ValueBuilder builder;
    Set(builder, value);
    return builder.ExtractValue();
}

template <typename T>
inline void Push(ValueBuilder& array_builder, const T& value) {
    array_builder.PushBack(ToJsonValue(value));
}

template <typename T>
inline void Put(ValueBuilder& builder, std::string_view key, const T& value) {
    using U = tg::internal::normalized_t<T>;
    const auto key_string = tg::internal::to_string(key);

    if constexpr (tg::internal::is_optional_true_v<U>) {
        if (!value) return;
        builder[key_string] = true;

    } else if constexpr (tg::internal::OptionalLike<U>) {
        if (!value) return;
        Put(builder, key, *value);

    } else if constexpr (tg::internal::UniquePtrLike<U>) {
        if (!value) return;
        Put(builder, key, *value);

    } else {
        builder[key_string] = ToJsonValue(value);
    }
}

}  // namespace tg::internal
