#include <types/file.hpp>
#include <types/mask_position.hpp>
#include <types/photo_size.hpp>
#include <types/sticker.hpp>

#include "common.hpp"

namespace tg {

Sticker Parse(const Value& value, To<Sticker>) {
    Sticker obj{};
    obj.file_id = ParseComplex<String>(value["file_id"]);
    obj.file_unique_id = ParseComplex<String>(value["file_unique_id"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.width = ParseComplex<Integer>(value["width"]);
    obj.height = ParseComplex<Integer>(value["height"]);
    obj.is_animated = ParseComplex<Boolean>(value["is_animated"]);
    obj.is_video = ParseComplex<Boolean>(value["is_video"]);
    obj.thumbnail = ParseComplex<Optional<PhotoSize>>(value["thumbnail"]);
    obj.emoji = ParseComplex<Optional<String>>(value["emoji"]);
    obj.set_name = ParseComplex<Optional<String>>(value["set_name"]);
    obj.premium_animation =
        ParseComplex<Optional<File>>(value["premium_animation"]);
    obj.mask_position =
        ParseComplex<Optional<MaskPosition>>(value["mask_position"]);
    obj.custom_emoji_id =
        ParseComplex<Optional<String>>(value["custom_emoji_id"]);
    obj.needs_repainting =
        ParseComplex<OptionalTrue>(value["needs_repainting"]);
    obj.file_size = ParseComplex<Optional<Integer>>(value["file_size"]);
    return obj;
}

}  // namespace tg
