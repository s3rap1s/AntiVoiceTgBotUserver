#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_markup.hpp>
#include <types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultArticle {
    String type;
    String id;
    String title;
    InputMessageContent input_message_content;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<String> url;
    Optional<String> description;
    Optional<String> thumbnail_url;
    Optional<Integer> thumbnail_width;
    Optional<Integer> thumbnail_height;
};

InlineQueryResultArticle Parse(const Value& value,
                               To<InlineQueryResultArticle>);

}  // namespace tg
