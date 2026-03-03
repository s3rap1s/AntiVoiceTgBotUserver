#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PreparedInlineMessage {
    String id;
    Integer expiration_date;
};

PreparedInlineMessage Parse(const Value& value, To<PreparedInlineMessage>);

void Serialize(const PreparedInlineMessage& obj, ValueBuilder& builder);

}  // namespace tg
