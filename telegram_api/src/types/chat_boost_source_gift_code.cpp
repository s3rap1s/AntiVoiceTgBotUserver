#include <tg/types/chat_boost_source_gift_code.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatBoostSourceGiftCode Parse(const Value& value, To<ChatBoostSourceGiftCode>) {
    ChatBoostSourceGiftCode obj{};
    obj.source = ParseComplex<String>(value["source"]);
    obj.user = ParseComplex<User>(value["user"]);
    return obj;
}

void Serialize(const ChatBoostSourceGiftCode& obj, ValueBuilder& builder) {
    internal::Put(builder, "source", obj.source);
    internal::Put(builder, "user", obj.user);
}

}  // namespace tg
