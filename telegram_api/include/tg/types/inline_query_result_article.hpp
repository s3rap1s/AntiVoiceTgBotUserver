#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

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

InlineQueryResultArticle Parse(const Value& value, To<InlineQueryResultArticle>);

void Serialize(const InlineQueryResultArticle& obj, ValueBuilder& builder);

}  // namespace tg
