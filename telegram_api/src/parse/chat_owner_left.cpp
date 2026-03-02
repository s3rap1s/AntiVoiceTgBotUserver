#include <tg/types/chat_owner_left.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChatOwnerLeft Parse(const Value& value, To<ChatOwnerLeft>) {
    ChatOwnerLeft obj{};
    obj.new_owner = ParseComplex<Optional<User>>(value["new_owner"]);
    return obj;
}

}  // namespace tg
