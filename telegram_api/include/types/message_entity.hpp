#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct MessageEntity {
    String type;
    Integer offset;
    Integer length;
    Optional<String> url;
    Optional<User> user;
    Optional<String> language;
    Optional<String> custom_emoji_id;
};

MessageEntity Parse(const Value& value, To<MessageEntity>);

}  // namespace tg
