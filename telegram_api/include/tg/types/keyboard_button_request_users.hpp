#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct KeyboardButtonRequestUsers {
    Integer request_id;
    Optional<Boolean> user_is_bot;
    Optional<Boolean> user_is_premium;
    Optional<Integer> max_quantity;
    Optional<Boolean> request_name;
    Optional<Boolean> request_username;
    Optional<Boolean> request_photo;
};

KeyboardButtonRequestUsers Parse(const Value& value,
                                 To<KeyboardButtonRequestUsers>);

}  // namespace tg
