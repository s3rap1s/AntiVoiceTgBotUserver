#include <tg/types/chat_boost.hpp>
#include <tg/types/user_chat_boosts.hpp>

#include "common.hpp"

namespace tg {

UserChatBoosts Parse(const Value& value, To<UserChatBoosts>) {
    UserChatBoosts obj{};
    obj.boosts = ParseComplex<Array<ChatBoost>>(value["boosts"]);
    return obj;
}

}  // namespace tg
