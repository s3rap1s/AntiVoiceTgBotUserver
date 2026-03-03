#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <userver/formats/json/value.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct VideoChatStarted {};

VideoChatStarted Parse(const userver::formats::json::Value& value, userver::formats::parse::To<VideoChatStarted>);

void Serialize(const VideoChatStarted& obj, ValueBuilder& builder);

}  // namespace tg
