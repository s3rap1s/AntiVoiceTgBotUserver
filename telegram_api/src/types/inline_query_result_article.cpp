#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_article.hpp>
#include <tg/types/input_message_content.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultArticle Parse(const Value& value, To<InlineQueryResultArticle>) {
    InlineQueryResultArticle obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.input_message_content = ParseComplex<InputMessageContent>(value["input_message_content"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.url = ParseComplex<Optional<String>>(value["url"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.thumbnail_url = ParseComplex<Optional<String>>(value["thumbnail_url"]);
    obj.thumbnail_width = ParseComplex<Optional<Integer>>(value["thumbnail_width"]);
    obj.thumbnail_height = ParseComplex<Optional<Integer>>(value["thumbnail_height"]);
    return obj;
}

void Serialize(const InlineQueryResultArticle& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "input_message_content", obj.input_message_content);
    internal::Put(builder, "reply_markup", obj.reply_markup);
    internal::Put(builder, "url", obj.url);
    internal::Put(builder, "description", obj.description);
    internal::Put(builder, "thumbnail_url", obj.thumbnail_url);
    internal::Put(builder, "thumbnail_width", obj.thumbnail_width);
    internal::Put(builder, "thumbnail_height", obj.thumbnail_height);
}

}  // namespace tg
