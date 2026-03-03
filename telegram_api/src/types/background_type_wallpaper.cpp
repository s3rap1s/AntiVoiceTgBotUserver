#include <tg/types/background_type_wallpaper.hpp>
#include <tg/types/document.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const BackgroundTypeWallpaper& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "document", obj.document);
    internal::Put(builder, "dark_theme_dimming", obj.dark_theme_dimming);
    internal::Put(builder, "is_blurred", obj.is_blurred);
    internal::Put(builder, "is_moving", obj.is_moving);
}

}  // namespace tg
