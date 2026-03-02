#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_markup.hpp>
#include <types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultMpeg4Gif {
    String type;
    String id;
    String mpeg4_url;
    Optional<Integer> mpeg4_width;
    Optional<Integer> mpeg4_height;
    Optional<Integer> mpeg4_duration;
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

InlineQueryResultMpeg4Gif Parse(const Value& value,
                                To<InlineQueryResultMpeg4Gif>);

}  // namespace tg
