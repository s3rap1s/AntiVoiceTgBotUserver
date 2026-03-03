#include <tg/types/photo_size.hpp>
#include <tg/types/sticker.hpp>
#include <tg/types/sticker_set.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StickerSet Parse(const Value& value, To<StickerSet>) {
    StickerSet obj{};
    obj.name = ParseComplex<String>(value["name"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.sticker_type = ParseComplex<String>(value["sticker_type"]);
    obj.stickers = ParseComplex<Array<Sticker>>(value["stickers"]);
    obj.thumbnail = ParseComplex<Optional<PhotoSize>>(value["thumbnail"]);
    return obj;
}

void Serialize(const StickerSet& obj, ValueBuilder& builder) {
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "sticker_type", obj.sticker_type);
    internal::Put(builder, "stickers", obj.stickers);
    internal::Put(builder, "thumbnail", obj.thumbnail);
}

}  // namespace tg
