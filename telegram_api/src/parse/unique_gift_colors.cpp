#include <tg/types/unique_gift_colors.hpp>

#include "common.hpp"

namespace tg {

UniqueGiftColors Parse(const Value& value, To<UniqueGiftColors>) {
    UniqueGiftColors obj{};
    obj.model_custom_emoji_id =
        ParseComplex<String>(value["model_custom_emoji_id"]);
    obj.symbol_custom_emoji_id =
        ParseComplex<String>(value["symbol_custom_emoji_id"]);
    obj.light_theme_main_color =
        ParseComplex<Integer>(value["light_theme_main_color"]);
    obj.light_theme_other_colors =
        ParseComplex<Array<Integer>>(value["light_theme_other_colors"]);
    obj.dark_theme_main_color =
        ParseComplex<Integer>(value["dark_theme_main_color"]);
    obj.dark_theme_other_colors =
        ParseComplex<Array<Integer>>(value["dark_theme_other_colors"]);
    return obj;
}

}  // namespace tg
