#pragma once

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultPhoto {
    String type;
    String id;
    String photo_url;
    String thumbnail_url;
    Optional<Integer> photo_width;
    Optional<Integer> photo_height;
    Optional<String> title;
    Optional<String> description;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultPhoto Parse(const Value& value, To<InlineQueryResultPhoto>);

}  // namespace tg
