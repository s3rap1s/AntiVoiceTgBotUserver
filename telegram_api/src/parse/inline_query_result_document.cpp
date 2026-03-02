#include <types/inline_keyboard_markup.hpp>
#include <types/inline_query_result_document.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultDocument Parse(const Value& value,
                                To<InlineQueryResultDocument>) {
    InlineQueryResultDocument obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.document_url = ParseComplex<Optional<String>>(value["document_url"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    obj.thumbnail_url = ParseComplex<Optional<String>>(value["thumbnail_url"]);
    obj.thumbnail_width =
        ParseComplex<Optional<Integer>>(value["thumbnail_width"]);
    obj.thumbnail_height =
        ParseComplex<Optional<Integer>>(value["thumbnail_height"]);
    return obj;
}

}  // namespace tg
