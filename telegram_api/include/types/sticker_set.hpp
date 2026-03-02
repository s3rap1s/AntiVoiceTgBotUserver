#pragma once

#include <types/common.hpp>
#include <types/photo_size.hpp>
#include <types/sticker.hpp>

namespace tg {

struct StickerSet {
    String name;
    String title;
    String sticker_type;
    Array<Sticker> stickers;
    Optional<PhotoSize> thumbnail;
};

StickerSet Parse(const Value& value, To<StickerSet>);

}  // namespace tg
