#include <types/video_chat_scheduled.hpp>

#include "common.hpp"

namespace tg {

VideoChatScheduled Parse(const Value& value, To<VideoChatScheduled>) {
    VideoChatScheduled obj{};
    obj.start_date = ParseComplex<Integer>(value["start_date"]);
    return obj;
}

}  // namespace tg
