#include <tg/types/keyboard_button.hpp>
#include <tg/types/keyboard_button_poll_type.hpp>
#include <tg/types/keyboard_button_request_chat.hpp>
#include <tg/types/keyboard_button_request_users.hpp>
#include <tg/types/web_app_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

KeyboardButton Parse(const Value& value, To<KeyboardButton>) {
    KeyboardButton obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.icon_custom_emoji_id = ParseComplex<Optional<String>>(value["icon_custom_emoji_id"]);
    obj.style = ParseComplex<Optional<String>>(value["style"]);
    obj.request_users = ParseComplex<Optional<KeyboardButtonRequestUsers>>(value["request_users"]);
    obj.request_chat = ParseComplex<Optional<KeyboardButtonRequestChat>>(value["request_chat"]);
    obj.request_contact = ParseComplex<Optional<Boolean>>(value["request_contact"]);
    obj.request_location = ParseComplex<Optional<Boolean>>(value["request_location"]);
    obj.request_poll = ParseComplex<Optional<KeyboardButtonPollType>>(value["request_poll"]);
    obj.web_app = ParseComplex<Optional<WebAppInfo>>(value["web_app"]);
    return obj;
}

void Serialize(const KeyboardButton& obj, ValueBuilder& builder) {
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "icon_custom_emoji_id", obj.icon_custom_emoji_id);
    internal::Put(builder, "style", obj.style);
    internal::Put(builder, "request_users", obj.request_users);
    internal::Put(builder, "request_chat", obj.request_chat);
    internal::Put(builder, "request_contact", obj.request_contact);
    internal::Put(builder, "request_location", obj.request_location);
    internal::Put(builder, "request_poll", obj.request_poll);
    internal::Put(builder, "web_app", obj.web_app);
}

}  // namespace tg
