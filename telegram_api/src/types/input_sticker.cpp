#include <tg/types/input_sticker.hpp>
#include <tg/types/mask_position.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputSticker Parse(const Value& value, To<InputSticker>) {
    InputSticker obj{};
    obj.sticker = ParseComplex<String>(value["sticker"]);
    obj.format = ParseComplex<String>(value["format"]);
    obj.emoji_list = ParseComplex<Array<String>>(value["emoji_list"]);
    obj.mask_position = ParseComplex<Optional<MaskPosition>>(value["mask_position"]);
    obj.keywords = ParseComplex<Optional<Array<String>>>(value["keywords"]);
    return obj;
}

void Serialize(const InputSticker& obj, ValueBuilder& builder) {
    internal::Put(builder, "sticker", obj.sticker);
    internal::Put(builder, "format", obj.format);
    internal::Put(builder, "emoji_list", obj.emoji_list);
    internal::Put(builder, "mask_position", obj.mask_position);
    internal::Put(builder, "keywords", obj.keywords);
}

}  // namespace tg
