#include <types/chat_owner_changed.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

ChatOwnerChanged Parse(const Value& value, To<ChatOwnerChanged>) {
    ChatOwnerChanged obj{};
    obj.new_owner = ParseComplex<Optional<User>>(value["new_owner"]);
    return obj;
}

}  // namespace tg
