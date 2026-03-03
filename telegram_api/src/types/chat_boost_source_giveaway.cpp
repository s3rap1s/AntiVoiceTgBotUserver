#include <tg/types/chat_boost_source_giveaway.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatBoostSourceGiveaway Parse(const Value& value, To<ChatBoostSourceGiveaway>) {
    ChatBoostSourceGiveaway obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.giveaway_message_id = ParseComplex<Integer>(value["giveaway_message_id"]);
    obj.user = ParseComplex<Optional<User>>(value["user"]);
    obj.prize_star_count = ParseComplex<Optional<Integer>>(value["prize_star_count"]);
    obj.is_unclaimed = ParseComplex<OptionalTrue>(value["is_unclaimed"]);
    return obj;
}

void Serialize(const ChatBoostSourceGiveaway& obj, ValueBuilder& builder) {
    internal::Put(builder, "source", obj.source);
    internal::Put(builder, "giveaway_message_id", obj.giveaway_message_id);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "prize_star_count", obj.prize_star_count);
    internal::Put(builder, "is_unclaimed", obj.is_unclaimed);
}

}  // namespace tg
