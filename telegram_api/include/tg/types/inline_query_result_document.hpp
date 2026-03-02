#pragma once

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultDocument {
    String type;
    String id;
    String title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<String> document_url;
    Optional<String> mime_type;
    Optional<String> description;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
    Optional<String> thumbnail_url;
    Optional<Integer> thumbnail_width;
    Optional<Integer> thumbnail_height;
};

InlineQueryResultDocument Parse(const Value& value,
                                To<InlineQueryResultDocument>);

}  // namespace tg
