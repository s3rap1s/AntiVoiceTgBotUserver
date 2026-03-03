#include <tg/types/chat_boost.hpp>
#include <tg/types/chat_boost_source.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const ChatBoost& obj, ValueBuilder& builder) {
    internal::Put(builder, "boost_id", obj.boost_id);
    internal::Put(builder, "add_date", obj.add_date);
    internal::Put(builder, "expiration_date", obj.expiration_date);
    internal::Put(builder, "source", obj.source);
}

}  // namespace tg
