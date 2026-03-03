#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct SwitchInlineQueryChosenChat {
    Optional<String> query;
    Optional<Boolean> allow_user_chats;
    Optional<Boolean> allow_bot_chats;
    Optional<Boolean> allow_group_chats;
    Optional<Boolean> allow_channel_chats;
};

SwitchInlineQueryChosenChat Parse(const Value& value, To<SwitchInlineQueryChosenChat>);

void Serialize(const SwitchInlineQueryChosenChat& obj, ValueBuilder& builder);

}  // namespace tg
