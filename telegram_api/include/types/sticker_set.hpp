#pragma once

#include "common.hpp"
#include "photo_size.hpp"
#include "sticker.hpp"

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
