#include <tg/types/unique_gift.hpp>
#include <tg/types/unique_gift_info.hpp>

#include "common.hpp"

namespace tg {

UniqueGiftInfo Parse(const Value& value, To<UniqueGiftInfo>) {
    UniqueGiftInfo obj{};
    obj.gift = ParseComplex<UniqueGift>(value["gift"]);
    obj.origin = ParseComplex<String>(value["origin"]);
    obj.last_resale_star_count =
        ParseComplex<Optional<Integer>>(value["last_resale_star_count"]);
    obj.owned_gift_id = ParseComplex<Optional<String>>(value["owned_gift_id"]);
    obj.transfer_star_count =
        ParseComplex<Optional<Integer>>(value["transfer_star_count"]);
    obj.next_transfer_date =
        ParseComplex<Optional<Integer>>(value["next_transfer_date"]);
    return obj;
}

}  // namespace tg
