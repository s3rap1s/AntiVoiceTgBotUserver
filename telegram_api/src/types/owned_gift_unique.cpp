#include <tg/types/owned_gift_unique.hpp>
#include <tg/types/unique_gift.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

OwnedGiftUnique Parse(const Value& value, To<OwnedGiftUnique>) {
    OwnedGiftUnique obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.gift = ParseComplex<UniqueGift>(value["gift"]);
    obj.owned_gift_id = ParseComplex<Optional<String>>(value["owned_gift_id"]);
    obj.sender_user = ParseComplex<Optional<User>>(value["sender_user"]);
    obj.send_date = ParseComplex<Integer>(value["send_date"]);
    obj.is_saved = ParseComplex<OptionalTrue>(value["is_saved"]);
    obj.can_be_transferred = ParseComplex<OptionalTrue>(value["can_be_transferred"]);
    obj.transfer_star_count = ParseComplex<Optional<Integer>>(value["transfer_star_count"]);
    obj.next_transfer_date = ParseComplex<Optional<Integer>>(value["next_transfer_date"]);
    return obj;
}

void Serialize(const OwnedGiftUnique& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "gift", obj.gift);
    internal::Put(builder, "owned_gift_id", obj.owned_gift_id);
    internal::Put(builder, "sender_user", obj.sender_user);
    internal::Put(builder, "send_date", obj.send_date);
    internal::Put(builder, "is_saved", obj.is_saved);
    internal::Put(builder, "can_be_transferred", obj.can_be_transferred);
    internal::Put(builder, "transfer_star_count", obj.transfer_star_count);
    internal::Put(builder, "next_transfer_date", obj.next_transfer_date);
}

}  // namespace tg
