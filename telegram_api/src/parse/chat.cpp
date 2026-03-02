#include <tg/types/chat.hpp>

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
    obj.is_direct_message =
        ParseComplex<OptionalTrue>(value["is_direct_message"]);
    return obj;
}

}  // namespace tg
