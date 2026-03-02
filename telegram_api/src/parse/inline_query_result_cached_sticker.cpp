#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_cached_sticker.hpp>
#include <tg/types/input_message_content.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultCachedSticker Parse(const Value& value,
                                     To<InlineQueryResultCachedSticker>) {
    InlineQueryResultCachedSticker obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.sticker_file_id = ParseComplex<String>(value["sticker_file_id"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    return obj;
}

}  // namespace tg
