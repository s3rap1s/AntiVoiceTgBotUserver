#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct MessageEntity {
    String type;
    Integer offset;
    Integer length;
    Optional<String> url;
    Optional<User> user;
    Optional<String> language;
    Optional<String> custom_emoji_id;
    Optional<Integer> unix_time;
    Optional<String> date_time_format;
};

MessageEntity Parse(const Value& value, To<MessageEntity>);

void Serialize(const MessageEntity& obj, ValueBuilder& builder);

}  // namespace tg
