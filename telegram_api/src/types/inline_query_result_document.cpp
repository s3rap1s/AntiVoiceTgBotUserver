#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_document.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultDocument Parse(const Value& value, To<InlineQueryResultDocument>) {
    InlineQueryResultDocument obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.document_url = ParseComplex<Optional<String>>(value["document_url"]);
    obj.mime_type = ParseComplex<Optional<String>>(value["mime_type"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(value["input_message_content"]);
    obj.thumbnail_url = ParseComplex<Optional<String>>(value["thumbnail_url"]);
    obj.thumbnail_width = ParseComplex<Optional<Integer>>(value["thumbnail_width"]);
    obj.thumbnail_height = ParseComplex<Optional<Integer>>(value["thumbnail_height"]);
    return obj;
}

void Serialize(const InlineQueryResultDocument& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "caption", obj.caption);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "caption_entities", obj.caption_entities);
    internal::Put(builder, "document_url", obj.document_url);
    internal::Put(builder, "mime_type", obj.mime_type);
    internal::Put(builder, "description", obj.description);
    internal::Put(builder, "reply_markup", obj.reply_markup);
    internal::Put(builder, "input_message_content", obj.input_message_content);
    internal::Put(builder, "thumbnail_url", obj.thumbnail_url);
    internal::Put(builder, "thumbnail_width", obj.thumbnail_width);
    internal::Put(builder, "thumbnail_height", obj.thumbnail_height);
}

}  // namespace tg
