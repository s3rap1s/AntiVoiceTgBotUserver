#include <tg/types/chat_boost_added.hpp>

#include "common.hpp"

namespace tg {

ChatBoostAdded Parse(const Value& value, To<ChatBoostAdded>) {
    ChatBoostAdded obj{};
    obj.boost_count = ParseComplex<Integer>(value["boost_count"]);
    return obj;
}

}  // namespace tg
