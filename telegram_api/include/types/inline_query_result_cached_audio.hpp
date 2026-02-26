#pragma once

#include "common.hpp"
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"
#include "message_entity.hpp"

namespace tg {

struct InlineQueryResultCachedAudio {
    String type;
    String id;
    String audio_file_id;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedAudio Parse(const Value& value,
                                   To<InlineQueryResultCachedAudio>);

}  // namespace tg
