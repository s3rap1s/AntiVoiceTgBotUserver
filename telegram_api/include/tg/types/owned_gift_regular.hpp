#pragma once

#include <tg/types/common.hpp>
#include <tg/types/gift.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct OwnedGiftRegular {
    String type;
    Gift gift;
    Optional<String> owned_gift_id;
    Optional<User> sender_user;
    Integer date;
    Optional<String> text;
    Optional<Array<MessageEntity>> entities;
    OptionalTrue is_private;
    OptionalTrue is_saved;
    OptionalTrue can_be_upgraded;
    OptionalTrue was_refunded;
    Optional<Integer> convert_star_count;
    Optional<Integer> prepaid_upgrade_star_count;
    OptionalTrue is_upgrade_separate;
    Optional<Integer> unique_gift_number;
};

OwnedGiftRegular Parse(const Value& value, To<OwnedGiftRegular>);

}  // namespace tg
