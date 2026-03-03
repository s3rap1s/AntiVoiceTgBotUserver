#include <tg/types/owned_gift.hpp>
#include <tg/types/owned_gifts.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

OwnedGifts Parse(const Value& value, To<OwnedGifts>) {
    OwnedGifts obj{};
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    obj.gifts = ParseComplex<Array<OwnedGift>>(value["gifts"]);
    obj.next_offset = ParseComplex<Optional<String>>(value["next_offset"]);
    return obj;
}

void Serialize(const OwnedGifts& obj, ValueBuilder& builder) {
    internal::Put(builder, "total_count", obj.total_count);
    internal::Put(builder, "gifts", obj.gifts);
    internal::Put(builder, "next_offset", obj.next_offset);
}

}  // namespace tg
