#pragma once

#include <types/common.hpp>
#include <types/maybe_inaccessible_message.hpp>
#include <types/user.hpp>

namespace tg {

struct CallbackQuery {
    String id;
    User from;
    Optional<MaybeInaccessibleMessage> message;
    Optional<String> inline_message_id;
    String chat_instance;
    Optional<String> data;
    Optional<String> game_short_name;
};

CallbackQuery Parse(const Value& value, To<CallbackQuery>);

}  // namespace tg
