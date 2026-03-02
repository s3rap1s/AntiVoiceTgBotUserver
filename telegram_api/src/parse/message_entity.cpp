#include <types/message_entity.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

MessageEntity Parse(const Value& value, To<MessageEntity>) {
    MessageEntity obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.offset = ParseComplex<Integer>(value["offset"]);
    obj.length = ParseComplex<Integer>(value["length"]);
    obj.url = ParseComplex<Optional<String>>(value["url"]);
    obj.user = ParseComplex<Optional<User>>(value["user"]);
    obj.language = ParseComplex<Optional<String>>(value["language"]);
    obj.custom_emoji_id =
        ParseComplex<Optional<String>>(value["custom_emoji_id"]);
    return obj;
}

}  // namespace tg
