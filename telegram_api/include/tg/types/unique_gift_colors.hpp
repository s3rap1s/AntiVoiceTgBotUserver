#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct UniqueGiftColors {
    String model_custom_emoji_id;
    String symbol_custom_emoji_id;
    Integer light_theme_main_color;
    Array<Integer> light_theme_other_colors;
    Integer dark_theme_main_color;
    Array<Integer> dark_theme_other_colors;
};

UniqueGiftColors Parse(const Value& value, To<UniqueGiftColors>);

}  // namespace tg
