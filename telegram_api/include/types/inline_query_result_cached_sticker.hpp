#pragma once

#include "common.hpp"
#include "inline_keyboard_markup.hpp"
#include "input_message_content.hpp"

namespace tg {

struct InlineQueryResultCachedSticker {
    String type;
    String id;
    String sticker_file_id;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
};

InlineQueryResultCachedSticker Parse(const Value& value,
                                     To<InlineQueryResultCachedSticker>);

}  // namespace tg
