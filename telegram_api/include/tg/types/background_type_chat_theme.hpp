#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BackgroundTypeChatTheme {
    String type;
    String theme_name;
};

BackgroundTypeChatTheme Parse(const Value& value, To<BackgroundTypeChatTheme>);

void Serialize(const BackgroundTypeChatTheme& obj, ValueBuilder& builder);

}  // namespace tg
