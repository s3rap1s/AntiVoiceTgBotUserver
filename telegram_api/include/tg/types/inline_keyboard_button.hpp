#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/callback_game.hpp>
#include <tg/types/common.hpp>
#include <tg/types/copy_text_button.hpp>
#include <tg/types/login_url.hpp>
#include <tg/types/switch_inline_query_chosen_chat.hpp>
#include <tg/types/web_app_info.hpp>

namespace tg {

struct InlineKeyboardButton {
    String text;
    Optional<String> icon_custom_emoji_id;
    Optional<String> style;
    Optional<String> url;
    Optional<String> callback_data;
    Optional<WebAppInfo> web_app;
    Optional<LoginUrl> login_url;
    Optional<String> switch_inline_query;
    Optional<String> switch_inline_query_current_chat;
    Optional<SwitchInlineQueryChosenChat> switch_inline_query_chosen_chat;
    Optional<CopyTextButton> copy_text;
    Optional<CallbackGame> callback_game;
    Optional<Boolean> pay;
};

InlineKeyboardButton Parse(const Value& value, To<InlineKeyboardButton>);

void Serialize(const InlineKeyboardButton& obj, ValueBuilder& builder);

}  // namespace tg
