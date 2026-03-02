#include <tg/types/chat.hpp>
#include <tg/types/inaccessible_message.hpp>

#include "common.hpp"

namespace tg {

InaccessibleMessage Parse(const Value& value, To<InaccessibleMessage>) {
    InaccessibleMessage obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    return obj;
}

}  // namespace tg
