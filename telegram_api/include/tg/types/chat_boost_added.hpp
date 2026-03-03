#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ChatBoostAdded {
    Integer boost_count;
};

ChatBoostAdded Parse(const Value& value, To<ChatBoostAdded>);

void Serialize(const ChatBoostAdded& obj, ValueBuilder& builder);

}  // namespace tg
