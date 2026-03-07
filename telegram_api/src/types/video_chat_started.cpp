#include <tg/types/video_chat_started.hpp>

#include "common.hpp"

namespace tg {

VideoChatStarted Parse(const Value& value, To<VideoChatStarted>) {
    (void)value;
    return VideoChatStarted{};
}

void Serialize(const VideoChatStarted& obj, ValueBuilder& builder) {
    (void)obj;
    (void)builder;
}

}  // namespace tg
