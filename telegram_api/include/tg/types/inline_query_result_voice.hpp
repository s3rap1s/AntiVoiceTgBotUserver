#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultVoice {
    String type;
    String id;
    String voice_url;
    String title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Integer> voice_duration;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultVoice Parse(const Value& value, To<InlineQueryResultVoice>);

void Serialize(const InlineQueryResultVoice& obj, ValueBuilder& builder);

}  // namespace tg
