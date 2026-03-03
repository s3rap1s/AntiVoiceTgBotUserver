#include <tg/types/chat.hpp>
#include <tg/types/chat_boost_removed.hpp>
#include <tg/types/chat_boost_source.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatBoostRemoved Parse(const Value& value, To<ChatBoostRemoved>) {
    ChatBoostRemoved obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.boost_id = ParseComplex<String>(value["boost_id"]);
    obj.remove_date = ParseComplex<Integer>(value["remove_date"]);
    obj.source = ParseComplex<ChatBoostSource>(value["source"]);
    return obj;
}

void Serialize(const ChatBoostRemoved& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "boost_id", obj.boost_id);
    internal::Put(builder, "remove_date", obj.remove_date);
    internal::Put(builder, "source", obj.source);
}

}  // namespace tg
