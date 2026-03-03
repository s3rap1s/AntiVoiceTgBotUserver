#include <tg/types/video_chat_scheduled.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

VideoChatScheduled Parse(const Value& value, To<VideoChatScheduled>) {
    VideoChatScheduled obj{};
    obj.start_date = ParseComplex<Integer>(value["start_date"]);
    return obj;
}

void Serialize(const VideoChatScheduled& obj, ValueBuilder& builder) {
    internal::Put(builder, "start_date", obj.start_date);
}

}  // namespace tg
