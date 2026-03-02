#include <tg/types/sticker.hpp>
#include <tg/types/unique_gift_model.hpp>

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

}  // namespace tg
