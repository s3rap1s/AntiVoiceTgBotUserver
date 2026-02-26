#pragma once

#include <userver/formats/json/value.hpp>

namespace tg {

struct ForumTopicReopened {};

ForumTopicReopened Parse(const userver::formats::json::Value& value,
                         userver::formats::parse::To<ForumTopicReopened>);

}  // namespace tg
