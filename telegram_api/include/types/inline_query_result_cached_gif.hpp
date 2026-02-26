#pragma once

#include "common.hpp"
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"
#include "message_entity.hpp"

namespace tg {

struct InlineQueryResultCachedGif {
    String type;
    String id;
    String gif_file_id;
    Optional<String> title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedGif Parse(const Value& value,
                                 To<InlineQueryResultCachedGif>);

}  // namespace tg
