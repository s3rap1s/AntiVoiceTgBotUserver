#pragma once

#include <tg/types/common.hpp>
#include <tg/types/mask_position.hpp>

namespace tg {

struct InputSticker {
    String sticker;
    String format;
    Array<String> emoji_list;
    Optional<MaskPosition> mask_position;
    Optional<Array<String>> keywords;
};

InputSticker Parse(const Value& value, To<InputSticker>);

}  // namespace tg
