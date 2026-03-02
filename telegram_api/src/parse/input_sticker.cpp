#include <types/input_sticker.hpp>
#include <types/mask_position.hpp>

#include "common.hpp"

namespace tg {

InputSticker Parse(const Value& value, To<InputSticker>) {
    InputSticker obj{};
    obj.sticker = ParseComplex<String>(value["sticker"]);
    obj.format = ParseComplex<String>(value["format"]);
    obj.emoji_list = ParseComplex<Array<String>>(value["emoji_list"]);
    obj.mask_position =
        ParseComplex<Optional<MaskPosition>>(value["mask_position"]);
    obj.keywords = ParseComplex<Optional<Array<String>>>(value["keywords"]);
    return obj;
}

}  // namespace tg
