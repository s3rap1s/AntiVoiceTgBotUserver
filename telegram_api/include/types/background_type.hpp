#pragma once

#include <types/background_type_chat_theme.hpp>
#include <types/background_type_fill.hpp>
#include <types/background_type_pattern.hpp>
#include <types/background_type_wallpaper.hpp>

namespace tg {

using BackgroundType = OneOf<BackgroundTypeFill, BackgroundTypeWallpaper,
                             BackgroundTypePattern, BackgroundTypeChatTheme>;

BackgroundType Parse(const Value& value, To<BackgroundType>);

}  // namespace tg
