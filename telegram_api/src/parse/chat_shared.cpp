#include <types/chat_shared.hpp>
#include <types/photo_size.hpp>

#include "common.hpp"

namespace tg {

ChatShared Parse(const Value& value, To<ChatShared>) {
    ChatShared obj{};
    obj.request_id = ParseComplex<Integer>(value["request_id"]);
    obj.chat_id = ParseComplex<Integer>(value["chat_id"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.username = ParseComplex<Optional<String>>(value["username"]);
    obj.photo = ParseComplex<Optional<Array<PhotoSize>>>(value["photo"]);
    return obj;
}

}  // namespace tg
