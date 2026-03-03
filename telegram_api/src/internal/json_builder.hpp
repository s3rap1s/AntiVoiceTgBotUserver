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
    using U = tg::internal::remove_cvref_t<T>;

    if constexpr (tg::internal::is_optional_true_v<U>) {
        if (value)
            builder = true;
        else
            builder = ValueBuilder();  // null

    } else if constexpr (tg::internal::is_optional_v<U>) {
        if (!value) {
            builder = ValueBuilder();  // null
            return;
        }
        using Inner = tg::internal::optional_inner_t<U>;
        Set(builder, static_cast<const Inner&>(*value));

    } else if constexpr (tg::internal::is_unique_ptr_v<U>) {
        if (!value) {
            builder = ValueBuilder();  // null
            return;
        }
        using Inner = tg::internal::unique_ptr_inner_t<U>;
        Set(builder, static_cast<const Inner&>(*value));

    } else if constexpr (tg::internal::is_vector_v<U>) {
        using Item = tg::internal::vector_inner_t<U>;
        ValueBuilder array_builder(Type::kArray);
        for (const auto& item : value) {
            ValueBuilder element_builder;
            Set(element_builder, static_cast<const Item&>(item));
            array_builder.PushBack(element_builder.ExtractValue());
        }
        builder = array_builder.ExtractValue();

    } else if constexpr (tg::internal::is_variant_v<U>) {
        std::visit([&](const auto& x) { Set(builder, x); }, value);

    } else if constexpr (HasSerialize<U>) {
        ValueBuilder object_builder(Type::kObject);
        Serialize(value, object_builder);
        builder = object_builder.ExtractValue();
    }
}

template <typename T>
inline void Push(ValueBuilder& array_builder, const T& value) {
    ValueBuilder element_builder;
    Set(element_builder, value);
    array_builder.PushBack(element_builder.ExtractValue());
}

template <typename T>
inline void Put(ValueBuilder& builder, std::string_view key, const T& value) {
    using U = tg::internal::remove_cvref_t<T>;

    if constexpr (tg::internal::is_optional_true_v<U>) {
        if (!value) return;
        builder[tg::internal::to_string(key)] = true;

    } else if constexpr (tg::internal::is_optional_v<U>) {
        if (!value) return;
        Put(builder, key, *value);

    } else if constexpr (tg::internal::is_unique_ptr_v<U>) {
        if (!value) return;
        Put(builder, key, *value);

    } else if constexpr (tg::internal::is_json_v<U>) {
        builder[tg::internal::to_string(key)] = value;

    } else if constexpr (std::is_same_v<U, String>) {
        builder[tg::internal::to_string(key)] = value;

    } else if constexpr (std::is_same_v<U, Boolean>) {
        builder[tg::internal::to_string(key)] = value;

    } else if constexpr (std::is_same_v<U, Float>) {
        builder[tg::internal::to_string(key)] = value;

    } else if constexpr (std::is_same_v<U, Integer>) {
        builder[tg::internal::to_string(key)] = value;

    } else {
        ValueBuilder tmp;
        Set(tmp, value);
        builder[tg::internal::to_string(key)] = tmp.ExtractValue();
    }
}

}  // namespace tg::internal