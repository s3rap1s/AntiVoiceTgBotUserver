#include <tg/types/message_auto_delete_timer_changed.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MessageAutoDeleteTimerChanged Parse(const Value& value, To<MessageAutoDeleteTimerChanged>) {
    MessageAutoDeleteTimerChanged obj{};
    obj.message_auto_delete_time = ParseComplex<Integer>(value["message_auto_delete_time"]);
    return obj;
}

void Serialize(const MessageAutoDeleteTimerChanged& obj, ValueBuilder& builder) {
    internal::Put(builder, "message_auto_delete_time", obj.message_auto_delete_time);
}

}  // namespace tg
