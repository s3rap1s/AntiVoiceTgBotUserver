#include <tg/types/background_type.hpp>
#include <tg/types/chat_background.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatBackground Parse(const Value& value, To<ChatBackground>) {
    ChatBackground obj{};
    obj.type = ParseComplex<BackgroundType>(value["type"]);
    return obj;
}

void Serialize(const ChatBackground& obj, ValueBuilder& builder) { internal::Put(builder, "type", obj.type); }

}  // namespace tg
