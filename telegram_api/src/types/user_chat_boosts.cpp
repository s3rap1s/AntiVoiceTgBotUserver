#include <tg/types/chat_boost.hpp>
#include <tg/types/user_chat_boosts.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UserChatBoosts Parse(const Value& value, To<UserChatBoosts>) {
    UserChatBoosts obj{};
    obj.boosts = ParseComplex<Array<ChatBoost>>(value["boosts"]);
    return obj;
}

void Serialize(const UserChatBoosts& obj, ValueBuilder& builder) { internal::Put(builder, "boosts", obj.boosts); }

}  // namespace tg
