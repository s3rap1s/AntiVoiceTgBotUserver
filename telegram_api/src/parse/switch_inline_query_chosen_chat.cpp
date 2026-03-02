#include <types/switch_inline_query_chosen_chat.hpp>

#include "common.hpp"

namespace tg {

SwitchInlineQueryChosenChat Parse(const Value& value,
                                  To<SwitchInlineQueryChosenChat>) {
    SwitchInlineQueryChosenChat obj{};
    obj.query = ParseComplex<Optional<String>>(value["query"]);
    obj.allow_user_chats =
        ParseComplex<Optional<Boolean>>(value["allow_user_chats"]);
    obj.allow_bot_chats =
        ParseComplex<Optional<Boolean>>(value["allow_bot_chats"]);
    obj.allow_group_chats =
        ParseComplex<Optional<Boolean>>(value["allow_group_chats"]);
    obj.allow_channel_chats =
        ParseComplex<Optional<Boolean>>(value["allow_channel_chats"]);
    return obj;
}

}  // namespace tg
