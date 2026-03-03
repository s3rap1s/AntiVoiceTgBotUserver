#include <tg/types/chat_boost_added.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatBoostAdded Parse(const Value& value, To<ChatBoostAdded>) {
    ChatBoostAdded obj{};
    obj.boost_count = ParseComplex<Integer>(value["boost_count"]);
    return obj;
}

void Serialize(const ChatBoostAdded& obj, ValueBuilder& builder) {
    internal::Put(builder, "boost_count", obj.boost_count);
}

}  // namespace tg
