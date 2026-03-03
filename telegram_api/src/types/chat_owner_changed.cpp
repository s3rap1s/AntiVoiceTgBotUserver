#include <tg/types/chat_owner_changed.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatOwnerChanged Parse(const Value& value, To<ChatOwnerChanged>) {
    ChatOwnerChanged obj{};
    obj.new_owner = ParseComplex<Optional<User>>(value["new_owner"]);
    return obj;
}

void Serialize(const ChatOwnerChanged& obj, ValueBuilder& builder) {
    internal::Put(builder, "new_owner", obj.new_owner);
}

}  // namespace tg
