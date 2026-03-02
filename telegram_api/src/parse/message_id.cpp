#include <tg/types/message_id.hpp>

#include "common.hpp"

namespace tg {

MessageId Parse(const Value& value, To<MessageId>) {
    MessageId obj{};
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    return obj;
}

}  // namespace tg
