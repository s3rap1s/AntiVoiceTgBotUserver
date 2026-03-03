#pragma once

#include <userver/formats/json/value_builder.hpp>

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

void Serialize(const BackgroundTypeWallpaper& obj, ValueBuilder& builder);

}  // namespace tg
