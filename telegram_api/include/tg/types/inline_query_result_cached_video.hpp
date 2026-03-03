#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"
#include "message_entity.hpp"

namespace tg {

struct InlineQueryResultCachedVideo {
    String type;
    String id;
    String video_file_id;
    Optional<String> title;
    Optional<String> description;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedVideo Parse(const Value& value, To<InlineQueryResultCachedVideo>);

void Serialize(const InlineQueryResultCachedVideo& obj, ValueBuilder& builder);

}  // namespace tg
