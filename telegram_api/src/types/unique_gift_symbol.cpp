#include <tg/types/sticker.hpp>
#include <tg/types/unique_gift_symbol.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UniqueGiftSymbol Parse(const Value& value, To<UniqueGiftSymbol>) {
    UniqueGiftSymbol obj{};
    obj.name = ParseComplex<String>(value["name"]);
    obj.sticker = ParseComplex<Sticker>(value["sticker"]);
    obj.rarity_per_mille = ParseComplex<Integer>(value["rarity_per_mille"]);
    return obj;
}

void Serialize(const UniqueGiftSymbol& obj, ValueBuilder& builder) {
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "sticker", obj.sticker);
    internal::Put(builder, "rarity_per_mille", obj.rarity_per_mille);
}

}  // namespace tg
