#include <types/background_type.hpp>
#include <types/chat_background.hpp>

#include "common.hpp"

namespace tg {

ChatBackground Parse(const Value& value, To<ChatBackground>) {
    ChatBackground obj{};
    obj.type = ParseComplex<BackgroundType>(value["type"]);
    return obj;
}

}  // namespace tg
