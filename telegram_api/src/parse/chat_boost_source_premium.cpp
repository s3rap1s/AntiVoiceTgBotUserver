#include <types/chat_boost_source_premium.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

ChatBoostSourcePremium Parse(const Value& value, To<ChatBoostSourcePremium>) {
    ChatBoostSourcePremium obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.user = ParseComplex<User>(value["user"]);
    return obj;
}

}  // namespace tg
