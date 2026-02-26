#pragma once

#include "common.hpp"
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"
#include "message_entity.hpp"

namespace tg {

struct InlineQueryResultCachedMpeg4Gif {
    String type;
    String id;
    String mpeg4_file_id;
    Optional<String> title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedMpeg4Gif Parse(const Value& value,
                                      To<InlineQueryResultCachedMpeg4Gif>);

}  // namespace tg
