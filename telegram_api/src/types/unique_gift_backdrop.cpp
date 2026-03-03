#include <tg/types/unique_gift_backdrop.hpp>
#include <tg/types/unique_gift_backdrop_colors.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UniqueGiftBackdrop Parse(const Value& value, To<UniqueGiftBackdrop>) {
    UniqueGiftBackdrop obj{};
    obj.name = ParseComplex<String>(value["name"]);
    obj.colors = ParseComplex<UniqueGiftBackdropColors>(value["colors"]);
    obj.rarity_per_mille = ParseComplex<Integer>(value["rarity_per_mille"]);
    return obj;
}

void Serialize(const UniqueGiftBackdrop& obj, ValueBuilder& builder) {
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "colors", obj.colors);
    internal::Put(builder, "rarity_per_mille", obj.rarity_per_mille);
}

}  // namespace tg
