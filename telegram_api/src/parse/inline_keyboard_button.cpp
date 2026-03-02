#include <types/callback_game.hpp>
#include <types/copy_text_button.hpp>
#include <types/inline_keyboard_button.hpp>
#include <types/login_url.hpp>
#include <types/switch_inline_query_chosen_chat.hpp>
#include <types/web_app_info.hpp>

#include "common.hpp"

namespace tg {

InlineKeyboardButton Parse(const Value& value, To<InlineKeyboardButton>) {
    InlineKeyboardButton obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.icon_custom_emoji_id =
        ParseComplex<Optional<String>>(value["icon_custom_emoji_id"]);
    obj.style = ParseComplex<Optional<String>>(value["style"]);
    obj.url = ParseComplex<Optional<String>>(value["url"]);
    obj.callback_data = ParseComplex<Optional<String>>(value["callback_data"]);
    obj.web_app = ParseComplex<Optional<WebAppInfo>>(value["web_app"]);
    obj.login_url = ParseComplex<Optional<LoginUrl>>(value["login_url"]);
    obj.switch_inline_query =
        ParseComplex<Optional<String>>(value["switch_inline_query"]);
    obj.switch_inline_query_current_chat = ParseComplex<Optional<String>>(
        value["switch_inline_query_current_chat"]);
    obj.switch_inline_query_chosen_chat =
        ParseComplex<Optional<SwitchInlineQueryChosenChat>>(
            value["switch_inline_query_chosen_chat"]);
    obj.copy_text = ParseComplex<Optional<CopyTextButton>>(value["copy_text"]);
    obj.callback_game =
        ParseComplex<Optional<CallbackGame>>(value["callback_game"]);
    obj.pay = ParseComplex<Optional<Boolean>>(value["pay"]);
    return obj;
}

}  // namespace tg
