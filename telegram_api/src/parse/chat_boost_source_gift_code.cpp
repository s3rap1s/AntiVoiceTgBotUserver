#include <tg/types/chat_boost_source_gift_code.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChatBoostSourceGiftCode Parse(const Value& value, To<ChatBoostSourceGiftCode>) {
    ChatBoostSourceGiftCode obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.user = ParseComplex<User>(value["user"]);
    return obj;
}

}  // namespace tg
