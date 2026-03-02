#pragma once

#include <types/common.hpp>

namespace tg {

struct UniqueGiftBackdropColors {
    Integer center_color;
    Integer edge_color;
    Integer symbol_color;
    Integer text_color;
};

UniqueGiftBackdropColors Parse(const Value& value,
                               To<UniqueGiftBackdropColors>);

}  // namespace tg
