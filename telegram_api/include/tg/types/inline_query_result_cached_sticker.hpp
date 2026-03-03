#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultCachedSticker {
    String type;
    String id;
    String sticker_file_id;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedSticker Parse(const Value& value, To<InlineQueryResultCachedSticker>);

void Serialize(const InlineQueryResultCachedSticker& obj, ValueBuilder& builder);

}  // namespace tg
