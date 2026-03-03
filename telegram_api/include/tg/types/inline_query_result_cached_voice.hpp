#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct InlineQueryResultCachedVoice {
    String type;
    String id;
    String voice_file_id;
    Optional<String> title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedVoice Parse(const Value& value, To<InlineQueryResultCachedVoice>);

void Serialize(const InlineQueryResultCachedVoice& obj, ValueBuilder& builder);

}  // namespace tg
