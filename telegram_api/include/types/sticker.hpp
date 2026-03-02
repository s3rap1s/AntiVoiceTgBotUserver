#pragma once

#include <types/common.hpp>
#include <types/file.hpp>
#include <types/mask_position.hpp>
#include <types/photo_size.hpp>

namespace tg {

struct Sticker {
    String file_id;
    String file_unique_id;
    String type;
    Integer width;
    Integer height;
    Boolean is_animated;
    Boolean is_video;
    Optional<PhotoSize> thumbnail;
    Optional<String> emoji;
    Optional<String> set_name;
    Optional<File> premium_animation;
    Optional<MaskPosition> mask_position;
    Optional<String> custom_emoji_id;
    OptionalTrue needs_repainting;
    Optional<Integer> file_size;
};

Sticker Parse(const Value& value, To<Sticker>);

}  // namespace tg
