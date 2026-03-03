#include <tg/types/chat.hpp>
#include <tg/types/story.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Story Parse(const Value& value, To<Story>) {
    Story obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.id = ParseComplex<Integer>(value["id"]);
    return obj;
}

void Serialize(const Story& obj, ValueBuilder& builder) {
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "id", obj.id);
}

}  // namespace tg
