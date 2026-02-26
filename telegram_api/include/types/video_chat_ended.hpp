#pragma once

#include <userver/formats/json/value.hpp>

namespace tg {

struct VideoChatEnded {};

VideoChatEnded Parse(const userver::formats::json::Value& value,
                     userver::formats::parse::To<VideoChatEnded>);

}  // namespace tg
