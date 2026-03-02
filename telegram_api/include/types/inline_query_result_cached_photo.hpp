#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_markup.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

namespace tg {

struct InlineQueryResultCachedPhoto {
    String type;
    String id;
    String photo_file_id;
    Optional<String> title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedPhoto Parse(const Value& value,
                                   To<InlineQueryResultCachedPhoto>);

}  // namespace tg
