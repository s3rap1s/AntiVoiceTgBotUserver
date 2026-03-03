#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <userver/formats/json/value.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct VideoChatEnded {};

VideoChatEnded Parse(const userver::formats::json::Value& value, userver::formats::parse::To<VideoChatEnded>);

void Serialize(const VideoChatEnded& obj, ValueBuilder& builder);

}  // namespace tg
