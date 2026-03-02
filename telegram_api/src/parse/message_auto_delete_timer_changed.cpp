#include <tg/types/message_auto_delete_timer_changed.hpp>

#include "common.hpp"

namespace tg {

MessageAutoDeleteTimerChanged Parse(const Value& value,
                                    To<MessageAutoDeleteTimerChanged>) {
    MessageAutoDeleteTimerChanged obj{};
    obj.message_auto_delete_time =
        ParseComplex<Integer>(value["message_auto_delete_time"]);
    return obj;
}

}  // namespace tg
