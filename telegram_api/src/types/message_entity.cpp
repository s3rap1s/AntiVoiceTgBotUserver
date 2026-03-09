#include <tg/types/message_entity.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
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
    obj.custom_emoji_id = ParseComplex<Optional<String>>(value["custom_emoji_id"]);
    obj.unix_time = ParseComplex<Optional<Integer>>(value["unix_time"]);
    obj.date_time_format = ParseComplex<Optional<String>>(value["date_time_format"]);
    return obj;
}

void Serialize(const MessageEntity& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "offset", obj.offset);
    internal::Put(builder, "length", obj.length);
    internal::Put(builder, "url", obj.url);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "language", obj.language);
    internal::Put(builder, "custom_emoji_id", obj.custom_emoji_id);
    internal::Put(builder, "unix_time", obj.unix_time);
    internal::Put(builder, "date_time_format", obj.date_time_format);
}

}  // namespace tg
