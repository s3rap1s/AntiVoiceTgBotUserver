#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <userver/formats/json/value.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

struct GeneralForumTopicHidden {};

GeneralForumTopicHidden Parse(const userver::formats::json::Value& value,
                              userver::formats::parse::To<GeneralForumTopicHidden>);

void Serialize(const GeneralForumTopicHidden& obj, ValueBuilder& builder);

}  // namespace tg
