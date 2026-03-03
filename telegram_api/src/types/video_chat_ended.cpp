#include <tg/types/video_chat_ended.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

VideoChatEnded Parse(const Value& value, To<VideoChatEnded>) {
    (void)value;
    return VideoChatEnded{};
}

void Serialize(const VideoChatEnded& obj, ValueBuilder& builder) {
    (void)obj;
    (void)builder;
}

}  // namespace tg
