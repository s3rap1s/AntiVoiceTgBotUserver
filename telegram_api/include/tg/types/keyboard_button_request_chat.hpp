#pragma once

#include <tg/types/chat_administrator_rights.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct KeyboardButtonRequestChat {
    Integer request_id;
    Boolean chat_is_channel;
    Optional<Boolean> chat_is_forum;
    Optional<Boolean> chat_has_username;
    Optional<Boolean> chat_is_created;
    Optional<ChatAdministratorRights> user_administrator_rights;
    Optional<ChatAdministratorRights> bot_administrator_rights;
    Optional<Boolean> bot_is_member;
    Optional<Boolean> request_title;
    Optional<Boolean> request_username;
    Optional<Boolean> request_photo;
};

KeyboardButtonRequestChat Parse(const Value& value,
                                To<KeyboardButtonRequestChat>);

}  // namespace tg
