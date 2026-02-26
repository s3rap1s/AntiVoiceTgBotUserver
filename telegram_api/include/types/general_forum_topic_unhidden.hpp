#pragma once

#include <userver/formats/json/value.hpp>

namespace tg {

struct GeneralForumTopicUnhidden {};

GeneralForumTopicUnhidden Parse(
    const userver::formats::json::Value& value,
    userver::formats::parse::To<GeneralForumTopicUnhidden>);

}  // namespace tg
