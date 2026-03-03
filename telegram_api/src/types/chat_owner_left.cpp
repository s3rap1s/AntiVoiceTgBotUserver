#include <tg/types/chat_owner_left.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatOwnerLeft Parse(const Value& value, To<ChatOwnerLeft>) {
    ChatOwnerLeft obj{};
    obj.new_owner = ParseComplex<Optional<User>>(value["new_owner"]);
    return obj;
}

void Serialize(const ChatOwnerLeft& obj, ValueBuilder& builder) { internal::Put(builder, "new_owner", obj.new_owner); }

}  // namespace tg
