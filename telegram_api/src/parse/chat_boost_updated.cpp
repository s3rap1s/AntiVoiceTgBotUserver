#include <tg/types/chat.hpp>
#include <tg/types/chat_boost.hpp>
#include <tg/types/chat_boost_updated.hpp>

#include "common.hpp"

namespace tg {

ChatBoostUpdated Parse(const Value& value, To<ChatBoostUpdated>) {
    ChatBoostUpdated obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.boost = ParseComplex<ChatBoost>(value["boost"]);
    return obj;
}

}  // namespace tg
