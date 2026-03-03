#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/unique_gift.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct OwnedGiftUnique {
    String type;
    UniqueGift gift;
    Optional<String> owned_gift_id;
    Optional<User> sender_user;
    Integer send_date;
    OptionalTrue is_saved;
    OptionalTrue can_be_transferred;
    Optional<Integer> transfer_star_count;
    Optional<Integer> next_transfer_date;
};

OwnedGiftUnique Parse(const Value& value, To<OwnedGiftUnique>);

void Serialize(const OwnedGiftUnique& obj, ValueBuilder& builder);

}  // namespace tg
