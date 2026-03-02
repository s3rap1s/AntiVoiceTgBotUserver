#pragma once

#include <types/common.hpp>
#include <types/keyboard_button_poll_type.hpp>
#include <types/keyboard_button_request_chat.hpp>
#include <types/keyboard_button_request_users.hpp>
#include <types/web_app_info.hpp>

namespace tg {

struct KeyboardButton {
    String text;
    Optional<String> icon_custom_emoji_id;
    Optional<String> style;
    Optional<KeyboardButtonRequestUsers> request_users;
    Optional<KeyboardButtonRequestChat> request_chat;
    Optional<Boolean> request_contact;
    Optional<Boolean> request_location;
    Optional<KeyboardButtonPollType> request_poll;
    Optional<WebAppInfo> web_app;
};

KeyboardButton Parse(const Value& value, To<KeyboardButton>);

}  // namespace tg
