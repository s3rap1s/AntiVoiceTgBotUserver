#include <tg/types/chat.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Chat Parse(const Value& value, To<Chat>) {
    Chat obj{};
    obj.id = ParseComplex<Integer>(value["id"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.username = ParseComplex<Optional<String>>(value["username"]);
    obj.first_name = ParseComplex<Optional<String>>(value["first_name"]);
    obj.last_name = ParseComplex<Optional<String>>(value["last_name"]);
    obj.is_forum = ParseComplex<OptionalTrue>(value["is_forum"]);
    obj.is_direct_message = ParseComplex<OptionalTrue>(value["is_direct_message"]);
    return obj;
}

void Serialize(const Chat& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "username", obj.username);
    internal::Put(builder, "first_name", obj.first_name);
    internal::Put(builder, "last_name", obj.last_name);
    internal::Put(builder, "is_forum", obj.is_forum);
    internal::Put(builder, "is_direct_message", obj.is_direct_message);
}

}  // namespace tg
