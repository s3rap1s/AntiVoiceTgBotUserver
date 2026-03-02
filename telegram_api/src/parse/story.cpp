#include <types/chat.hpp>
#include <types/story.hpp>

#include "common.hpp"

namespace tg {

Story Parse(const Value& value, To<Story>) {
    Story obj{};
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.id = ParseComplex<Integer>(value["id"]);
    return obj;
}

}  // namespace tg
