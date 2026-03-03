#include <tg/types/sticker.hpp>
#include <tg/types/unique_gift_model.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UniqueGiftModel Parse(const Value& value, To<UniqueGiftModel>) {
    UniqueGiftModel obj{};
    obj.name = ParseComplex<String>(value["name"]);
    obj.sticker = ParseComplex<Sticker>(value["sticker"]);
    obj.rarity_per_mille = ParseComplex<Integer>(value["rarity_per_mille"]);
    obj.rarity = ParseComplex<Optional<String>>(value["rarity"]);
    return obj;
}

void Serialize(const UniqueGiftModel& obj, ValueBuilder& builder) {
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "sticker", obj.sticker);
    internal::Put(builder, "rarity_per_mille", obj.rarity_per_mille);
    internal::Put(builder, "rarity", obj.rarity);
}

}  // namespace tg
