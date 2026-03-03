#pragma once

#include <userver/formats/json/value_builder.hpp>

#include "background_type.hpp"

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct ChatBackground {
    BackgroundType type;
};

ChatBackground Parse(const Value& value, To<ChatBackground>);

void Serialize(const ChatBackground& obj, ValueBuilder& builder);

}  // namespace tg
