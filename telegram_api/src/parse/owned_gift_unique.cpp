#include <tg/types/owned_gift_unique.hpp>
#include <tg/types/unique_gift.hpp>
#include <tg/types/user.hpp>

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
    obj.can_be_transferred =
        ParseComplex<OptionalTrue>(value["can_be_transferred"]);
    obj.transfer_star_count =
        ParseComplex<Optional<Integer>>(value["transfer_star_count"]);
    obj.next_transfer_date =
        ParseComplex<Optional<Integer>>(value["next_transfer_date"]);
    return obj;
}

}  // namespace tg
