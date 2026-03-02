#include <tg/types/background_type_wallpaper.hpp>
#include <tg/types/document.hpp>

#include "common.hpp"

namespace tg {

BackgroundTypeWallpaper Parse(const Value& value, To<BackgroundTypeWallpaper>) {
    BackgroundTypeWallpaper obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.document = ParseComplex<Document>(value["document"]);
    obj.dark_theme_dimming = ParseComplex<Integer>(value["dark_theme_dimming"]);
    obj.is_blurred = ParseComplex<OptionalTrue>(value["is_blurred"]);
    obj.is_moving = ParseComplex<OptionalTrue>(value["is_moving"]);
    return obj;
}

}  // namespace tg
