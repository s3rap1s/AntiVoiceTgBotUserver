#include <tg/types/chat.hpp>
#include <tg/types/chat_boost.hpp>
#include <tg/types/chat_boost_updated.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatBoostUpdated Parse(const Value& value, To<ChatBoostUpdated>) {
    ChatBoostUpdated obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.boost = ParseComplex<ChatBoost>(value["boost"]);
    return obj;
}

void Serialize(const ChatBoostUpdated& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "boost", obj.boost);
}

}  // namespace tg
