#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultVideo {
    String type;
    String id;
    String video_url;
    String mime_type;
    String thumbnail_url;
    String title;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<Integer> video_width;
    Optional<Integer> video_height;
    Optional<Integer> video_duration;
    Optional<String> description;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultVideo Parse(const Value& value, To<InlineQueryResultVideo>);

void Serialize(const InlineQueryResultVideo& obj, ValueBuilder& builder);

}  // namespace tg
