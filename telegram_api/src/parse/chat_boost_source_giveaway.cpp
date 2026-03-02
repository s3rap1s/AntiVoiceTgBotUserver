#include <tg/types/chat_boost_source_giveaway.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChatBoostSourceGiveaway Parse(const Value& value, To<ChatBoostSourceGiveaway>) {
    ChatBoostSourceGiveaway obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.giveaway_message_id =
        ParseComplex<Integer>(value["giveaway_message_id"]);
    obj.user = ParseComplex<Optional<User>>(value["user"]);
    obj.prize_star_count =
        ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    obj.is_unclaimed = ParseComplex<OptionalTrue>(value["is_unclaimed"]);
    return obj;
}

}  // namespace tg
