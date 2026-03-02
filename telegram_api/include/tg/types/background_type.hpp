#pragma once

#include <tg/types/background_type_chat_theme.hpp>
#include <tg/types/background_type_fill.hpp>
#include <tg/types/background_type_pattern.hpp>
#include <tg/types/background_type_wallpaper.hpp>

namespace tg {

using BackgroundType = OneOf<BackgroundTypeFill, BackgroundTypeWallpaper,
                             BackgroundTypePattern, BackgroundTypeChatTheme>;

BackgroundType Parse(const Value& value, To<BackgroundType>);

}  // namespace tg
