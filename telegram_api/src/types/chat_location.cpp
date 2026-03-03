#include <tg/types/chat_location.hpp>
#include <tg/types/location.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatLocation Parse(const Value& value, To<ChatLocation>) {
    ChatLocation obj{};
    obj.location = ParseComplex<Location>(value["location"]);
    obj.address = ParseComplex<String>(value["address"]);
    return obj;
}

void Serialize(const ChatLocation& obj, ValueBuilder& builder) {
    internal::Put(builder, "location", obj.location);
    internal::Put(builder, "address", obj.address);
}

}  // namespace tg
