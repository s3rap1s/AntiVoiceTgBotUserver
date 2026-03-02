#include <types/message_origin_user.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

MessageOriginUser Parse(const Value& value, To<MessageOriginUser>) {
    MessageOriginUser obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.sender_user = ParseComplex<User>(value["sender_user"]);
    return obj;
}

}  // namespace tg
