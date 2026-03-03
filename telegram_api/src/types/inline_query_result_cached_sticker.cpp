#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_cached_sticker.hpp>
#include <tg/types/input_message_content.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultCachedSticker Parse(const Value& value, To<InlineQueryResultCachedSticker>) {
    InlineQueryResultCachedSticker obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.sticker_file_id = ParseComplex<String>(value["sticker_file_id"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(value["input_message_content"]);
    return obj;
}

void Serialize(const InlineQueryResultCachedSticker& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "sticker_file_id", obj.sticker_file_id);
    internal::Put(builder, "reply_markup", obj.reply_markup);
    internal::Put(builder, "input_message_content", obj.input_message_content);
}

}  // namespace tg
