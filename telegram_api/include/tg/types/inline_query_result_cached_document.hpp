#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct InlineQueryResultCachedDocument {
    String type;
    String id;
    String title;
    String document_file_id;
    Optional<String> description;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedDocument Parse(const Value& value, To<InlineQueryResultCachedDocument>);

void Serialize(const InlineQueryResultCachedDocument& obj, ValueBuilder& builder);

}  // namespace tg
