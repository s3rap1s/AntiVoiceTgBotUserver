#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_markup.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

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
