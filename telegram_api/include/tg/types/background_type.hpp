#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/background_type_chat_theme.hpp>
#include <tg/types/background_type_fill.hpp>
#include <tg/types/background_type_pattern.hpp>
#include <tg/types/background_type_wallpaper.hpp>

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

using BackgroundType =
    OneOf<BackgroundTypeFill, BackgroundTypeWallpaper, BackgroundTypePattern, BackgroundTypeChatTheme>;

BackgroundType Parse(const Value& value, To<BackgroundType>);

void Serialize(const BackgroundType& obj, ValueBuilder& builder);

}  // namespace tg
