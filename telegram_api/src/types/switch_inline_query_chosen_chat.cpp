#include <tg/types/switch_inline_query_chosen_chat.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SwitchInlineQueryChosenChat Parse(const Value& value, To<SwitchInlineQueryChosenChat>) {
    SwitchInlineQueryChosenChat obj{};
    obj.query = ParseComplex<Optional<String>>(value["query"]);
    obj.allow_user_chats = ParseComplex<Optional<Boolean>>(value["allow_user_chats"]);
    obj.allow_bot_chats = ParseComplex<Optional<Boolean>>(value["allow_bot_chats"]);
    obj.allow_group_chats = ParseComplex<Optional<Boolean>>(value["allow_group_chats"]);
    obj.allow_channel_chats = ParseComplex<Optional<Boolean>>(value["allow_channel_chats"]);
    return obj;
}

void Serialize(const SwitchInlineQueryChosenChat& obj, ValueBuilder& builder) {
    internal::Put(builder, "query", obj.query);
    internal::Put(builder, "allow_user_chats", obj.allow_user_chats);
    internal::Put(builder, "allow_bot_chats", obj.allow_bot_chats);
    internal::Put(builder, "allow_group_chats", obj.allow_group_chats);
    internal::Put(builder, "allow_channel_chats", obj.allow_channel_chats);
}

}  // namespace tg
