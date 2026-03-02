#include <types/owned_gift.hpp>
#include <types/owned_gifts.hpp>

#include "common.hpp"

namespace tg {

OwnedGifts Parse(const Value& value, To<OwnedGifts>) {
    OwnedGifts obj{};
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    obj.gifts = ParseComplex<Array<OwnedGift>>(value["gifts"]);
    obj.next_offset = ParseComplex<Optional<String>>(value["next_offset"]);
    return obj;
}

}  // namespace tg
