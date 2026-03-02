#include <types/chat.hpp>
#include <types/chat_boost_removed.hpp>
#include <types/chat_boost_source.hpp>

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

}  // namespace tg
