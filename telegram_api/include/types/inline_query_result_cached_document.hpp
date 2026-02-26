#pragma once

#include "common.hpp"
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"
#include "message_entity.hpp"

namespace tg {

struct InlineQueryResultCachedDocument {
    String type;
    String id;
    String title;
    String document_file_id;
    Optional<String> description;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedDocument Parse(const Value& value,
                                      To<InlineQueryResultCachedDocument>);

}  // namespace tg
