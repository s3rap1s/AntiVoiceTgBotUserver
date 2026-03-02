#include <tg/types/unique_gift_backdrop.hpp>
#include <tg/types/unique_gift_backdrop_colors.hpp>

#include "common.hpp"

namespace tg {

UniqueGiftBackdrop Parse(const Value& value, To<UniqueGiftBackdrop>) {
    UniqueGiftBackdrop obj{};
    obj.name = ParseComplex<String>(value["name"]);
    obj.colors = ParseComplex<UniqueGiftBackdropColors>(value["colors"]);
    obj.rarity_per_mille = ParseComplex<Integer>(value["rarity_per_mille"]);
    return obj;
}

}  // namespace tg
