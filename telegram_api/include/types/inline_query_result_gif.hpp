#pragma once

#include "common.hpp"
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"

namespace tg {

struct InlineQueryResultGif {
    String type;
    String id;
    String gif_url;
    Optional<Integer> gif_width;
    Optional<Integer> gif_height;
    Optional<Integer> gif_duration;
    String thumbnail_url;
    Optional<String> thumbnail_mime_type;
    Optional<String> title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultGif Parse(const Value& value, To<InlineQueryResultGif>);

}  // namespace tg
