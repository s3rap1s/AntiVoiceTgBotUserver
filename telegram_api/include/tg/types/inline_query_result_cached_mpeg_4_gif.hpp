#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

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

InlineQueryResultCachedMpeg4Gif Parse(const Value& value, To<InlineQueryResultCachedMpeg4Gif>);

void Serialize(const InlineQueryResultCachedMpeg4Gif& obj, ValueBuilder& builder);

}  // namespace tg
