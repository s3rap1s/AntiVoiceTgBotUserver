#pragma once

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultAudio {
    String type;
    String id;
    String audio_url;
    String title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<String> performer;
    Optional<Integer> audio_duration;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultAudio Parse(const Value& value, To<InlineQueryResultAudio>);

}  // namespace tg
