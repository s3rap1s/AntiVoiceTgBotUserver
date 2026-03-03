#include <tg/types/chat_administrator_rights.hpp>
#include <tg/types/keyboard_button_request_chat.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

KeyboardButtonRequestChat Parse(const Value& value, To<KeyboardButtonRequestChat>) {
    KeyboardButtonRequestChat obj{};
    obj.request_id = ParseComplex<Integer>(value["request_id"]);
    obj.chat_is_channel = ParseComplex<Boolean>(value["chat_is_channel"]);
    obj.chat_is_forum = ParseComplex<Optional<Boolean>>(value["chat_is_forum"]);
    obj.chat_has_username = ParseComplex<Optional<Boolean>>(value["chat_has_username"]);
    obj.chat_is_created = ParseComplex<Optional<Boolean>>(value["chat_is_created"]);
    obj.user_administrator_rights = ParseComplex<Optional<ChatAdministratorRights>>(value["user_administrator_rights"]);
    obj.bot_administrator_rights = ParseComplex<Optional<ChatAdministratorRights>>(value["bot_administrator_rights"]);
    obj.bot_is_member = ParseComplex<Optional<Boolean>>(value["bot_is_member"]);
    obj.request_title = ParseComplex<Optional<Boolean>>(value["request_title"]);
    obj.request_username = ParseComplex<Optional<Boolean>>(value["request_username"]);
    obj.request_photo = ParseComplex<Optional<Boolean>>(value["request_photo"]);
    return obj;
}

void Serialize(const KeyboardButtonRequestChat& obj, ValueBuilder& builder) {
    internal::Put(builder, "request_id", obj.request_id);
    internal::Put(builder, "chat_is_channel", obj.chat_is_channel);
    internal::Put(builder, "chat_is_forum", obj.chat_is_forum);
    internal::Put(builder, "chat_has_username", obj.chat_has_username);
    internal::Put(builder, "chat_is_created", obj.chat_is_created);
    internal::Put(builder, "user_administrator_rights", obj.user_administrator_rights);
    internal::Put(builder, "bot_administrator_rights", obj.bot_administrator_rights);
    internal::Put(builder, "bot_is_member", obj.bot_is_member);
    internal::Put(builder, "request_title", obj.request_title);
    internal::Put(builder, "request_username", obj.request_username);
    internal::Put(builder, "request_photo", obj.request_photo);
}

}  // namespace tg
