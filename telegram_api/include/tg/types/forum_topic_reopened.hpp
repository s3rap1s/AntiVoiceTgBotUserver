#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <userver/formats/json/value.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct ForumTopicReopened {};

ForumTopicReopened Parse(const userver::formats::json::Value& value, userver::formats::parse::To<ForumTopicReopened>);

void Serialize(const ForumTopicReopened& obj, ValueBuilder& builder);

}  // namespace tg
