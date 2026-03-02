#include <types/chat_boost.hpp>
#include <types/chat_boost_source.hpp>

#include "common.hpp"

namespace tg {

ChatBoost Parse(const Value& value, To<ChatBoost>) {
    ChatBoost obj{};
    obj.boost_id = ParseComplex<String>(value["boost_id"]);
    obj.add_date = ParseComplex<Integer>(value["add_date"]);
    obj.expiration_date = ParseComplex<Integer>(value["expiration_date"]);
    obj.source = ParseComplex<ChatBoostSource>(value["source"]);
    return obj;
}

}  // namespace tg
