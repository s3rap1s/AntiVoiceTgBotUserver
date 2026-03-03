#include <tg/types/unique_gift.hpp>
#include <tg/types/unique_gift_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UniqueGiftInfo Parse(const Value& value, To<UniqueGiftInfo>) {
    UniqueGiftInfo obj{};
    obj.gift = ParseComplex<UniqueGift>(value["gift"]);
    obj.origin = ParseComplex<String>(value["origin"]);
    obj.last_resale_star_count = ParseComplex<Optional<Integer>>(value["last_resale_star_count"]);
    obj.owned_gift_id = ParseComplex<Optional<String>>(value["owned_gift_id"]);
    obj.transfer_star_count = ParseComplex<Optional<Integer>>(value["transfer_star_count"]);
    obj.next_transfer_date = ParseComplex<Optional<Integer>>(value["next_transfer_date"]);
    return obj;
}

void Serialize(const UniqueGiftInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "gift", obj.gift);
    internal::Put(builder, "origin", obj.origin);
    internal::Put(builder, "last_resale_star_count", obj.last_resale_star_count);
    internal::Put(builder, "owned_gift_id", obj.owned_gift_id);
    internal::Put(builder, "transfer_star_count", obj.transfer_star_count);
    internal::Put(builder, "next_transfer_date", obj.next_transfer_date);
}

}  // namespace tg
