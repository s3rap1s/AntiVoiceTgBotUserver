#include <types/background_type.hpp>
#include <types/background_type_chat_theme.hpp>
#include <types/background_type_fill.hpp>
#include <types/background_type_pattern.hpp>
#include <types/background_type_wallpaper.hpp>

#include "common.hpp"

namespace tg {

BackgroundType Parse(const Value& value, To<BackgroundType>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "fill") return ParseComplex<BackgroundTypeFill>(value);
    if (type == "wallpaper")
        return ParseComplex<BackgroundTypeWallpaper>(value);
    if (type == "pattern") return ParseComplex<BackgroundTypePattern>(value);
    if (type == "chat_theme")
        return ParseComplex<BackgroundTypeChatTheme>(value);
    throw std::runtime_error("Unknown BackgroundType type: " + type);
}

}  // namespace tg
