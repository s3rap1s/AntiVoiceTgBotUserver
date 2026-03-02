#pragma once

#include <types/common.hpp>
#include <types/photo_size.hpp>

namespace tg {

struct ChatShared {
    Integer request_id;
    Integer chat_id;
    Optional<String> title;
    Optional<String> username;
    Optional<Array<PhotoSize>> photo;
};

ChatShared Parse(const Value& value, To<ChatShared>);

}  // namespace tg
