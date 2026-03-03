#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <userver/formats/json/value.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct GeneralForumTopicUnhidden {};

GeneralForumTopicUnhidden Parse(const userver::formats::json::Value& value,
                                userver::formats::parse::To<GeneralForumTopicUnhidden>);

void Serialize(const GeneralForumTopicUnhidden& obj, ValueBuilder& builder);

}  // namespace tg
