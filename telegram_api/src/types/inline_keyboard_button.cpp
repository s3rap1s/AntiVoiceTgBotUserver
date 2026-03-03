#include <tg/types/callback_game.hpp>
#include <tg/types/copy_text_button.hpp>
#include <tg/types/inline_keyboard_button.hpp>
#include <tg/types/login_url.hpp>
#include <tg/types/switch_inline_query_chosen_chat.hpp>
#include <tg/types/web_app_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineKeyboardButton Parse(const Value& value, To<InlineKeyboardButton>) {
    InlineKeyboardButton obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.icon_custom_emoji_id = ParseComplex<Optional<String>>(value["icon_custom_emoji_id"]);
    obj.style = ParseComplex<Optional<String>>(value["style"]);
    obj.url = ParseComplex<Optional<String>>(value["url"]);
    obj.callback_data = ParseComplex<Optional<String>>(value["callback_data"]);
    obj.web_app = ParseComplex<Optional<WebAppInfo>>(value["web_app"]);
    obj.login_url = ParseComplex<Optional<LoginUrl>>(value["login_url"]);
    obj.switch_inline_query = ParseComplex<Optional<String>>(value["switch_inline_query"]);
    obj.switch_inline_query_current_chat = ParseComplex<Optional<String>>(value["switch_inline_query_current_chat"]);
    obj.switch_inline_query_chosen_chat =
        ParseComplex<Optional<SwitchInlineQueryChosenChat>>(value["switch_inline_query_chosen_chat"]);
    obj.copy_text = ParseComplex<Optional<CopyTextButton>>(value["copy_text"]);
    obj.callback_game = ParseComplex<Optional<CallbackGame>>(value["callback_game"]);
    obj.pay = ParseComplex<Optional<Boolean>>(value["pay"]);
    return obj;
}

void Serialize(const InlineKeyboardButton& obj, ValueBuilder& builder) {
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "icon_custom_emoji_id", obj.icon_custom_emoji_id);
    internal::Put(builder, "style", obj.style);
    internal::Put(builder, "url", obj.url);
    internal::Put(builder, "callback_data", obj.callback_data);
    internal::Put(builder, "web_app", obj.web_app);
    internal::Put(builder, "login_url", obj.login_url);
    internal::Put(builder, "switch_inline_query", obj.switch_inline_query);
    internal::Put(builder, "switch_inline_query_current_chat", obj.switch_inline_query_current_chat);
    internal::Put(builder, "switch_inline_query_chosen_chat", obj.switch_inline_query_chosen_chat);
    internal::Put(builder, "copy_text", obj.copy_text);
    internal::Put(builder, "callback_game", obj.callback_game);
    internal::Put(builder, "pay", obj.pay);
}

}  // namespace tg
