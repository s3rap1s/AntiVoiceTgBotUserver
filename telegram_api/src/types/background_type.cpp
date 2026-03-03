#include <tg/types/background_type.hpp>
#include <tg/types/background_type_chat_theme.hpp>
#include <tg/types/background_type_fill.hpp>
#include <tg/types/background_type_pattern.hpp>
#include <tg/types/background_type_wallpaper.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BackgroundType Parse(const Value& value, To<BackgroundType>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "fill") return ParseComplex<BackgroundTypeFill>(value);
    if (type == "wallpaper") return ParseComplex<BackgroundTypeWallpaper>(value);
    if (type == "pattern") return ParseComplex<BackgroundTypePattern>(value);
    if (type == "chat_theme") return ParseComplex<BackgroundTypeChatTheme>(value);
    throw ParseException("Unknown BackgroundType type: " + type);
}

void Serialize(const BackgroundType& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
