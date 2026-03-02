#pragma once

#include <tg/types/common.hpp>
#include <tg/types/document.hpp>

namespace tg {

struct BackgroundTypeWallpaper {
    String type;
    Document document;
    Integer dark_theme_dimming;
    OptionalTrue is_blurred;
    OptionalTrue is_moving;
};

BackgroundTypeWallpaper Parse(const Value& value, To<BackgroundTypeWallpaper>);

}  // namespace tg
