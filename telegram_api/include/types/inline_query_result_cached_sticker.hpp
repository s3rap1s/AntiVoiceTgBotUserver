#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_markup.hpp>
#include <types/input_message_content.hpp>

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
