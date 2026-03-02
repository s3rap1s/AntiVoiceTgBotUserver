#include <tg/types/background_type.hpp>
#include <tg/types/chat_background.hpp>

#include "common.hpp"

namespace tg {

ChatBackground Parse(const Value& value, To<ChatBackground>) {
    ChatBackground obj{};
    obj.type = ParseComplex<BackgroundType>(value["type"]);
    return obj;
}

}  // namespace tg
