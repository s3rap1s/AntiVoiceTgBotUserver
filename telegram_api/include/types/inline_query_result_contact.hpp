#pragma once

#include "common.hpp"
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"

namespace tg {

struct InlineQueryResultContact {
    String type;
    String id;
    String phone_number;
    String first_name;
    Optional<String> last_name;
    Optional<String> vcard;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
    Optional<String> thumbnail_url;
    Optional<Integer> thumbnail_width;
    Optional<Integer> thumbnail_height;
};

InlineQueryResultContact Parse(const Value& value,
                               To<InlineQueryResultContact>);

}  // namespace tg
