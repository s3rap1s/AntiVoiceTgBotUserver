#pragma once

#include <userver/formats/json/value.hpp>

namespace tg {

struct GeneralForumTopicHidden {};

GeneralForumTopicHidden Parse(
    const userver::formats::json::Value& value,
    userver::formats::parse::To<GeneralForumTopicHidden>);

}  // namespace tg
