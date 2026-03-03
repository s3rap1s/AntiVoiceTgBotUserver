#include <tg/types/chat_shared.hpp>
#include <tg/types/photo_size.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const ChatShared& obj, ValueBuilder& builder) {
    internal::Put(builder, "request_id", obj.request_id);
    internal::Put(builder, "chat_id", obj.chat_id);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "username", obj.username);
    internal::Put(builder, "photo", obj.photo);
}

}  // namespace tg
