#include <types/inline_keyboard_markup.hpp>
#include <types/inline_query_result_cached_document.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultCachedDocument Parse(const Value& value,
                                      To<InlineQueryResultCachedDocument>) {
    InlineQueryResultCachedDocument obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.document_file_id = ParseComplex<String>(value["document_file_id"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    return obj;
}

}  // namespace tg
