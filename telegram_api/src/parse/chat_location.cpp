#include <tg/types/chat_location.hpp>
#include <tg/types/location.hpp>

#include "common.hpp"

namespace tg {

ChatLocation Parse(const Value& value, To<ChatLocation>) {
    ChatLocation obj{};
    obj.location = ParseComplex<Location>(value["location"]);
    obj.address = ParseComplex<String>(value["address"]);
    return obj;
}

}  // namespace tg
