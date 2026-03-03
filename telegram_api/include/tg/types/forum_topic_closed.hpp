#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <userver/formats/json/value.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct ForumTopicClosed {};

ForumTopicClosed Parse(const userver::formats::json::Value& value, userver::formats::parse::To<ForumTopicClosed>);

void Serialize(const ForumTopicClosed& obj, ValueBuilder& builder);

}  // namespace tg
