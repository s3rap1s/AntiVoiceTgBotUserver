#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_article.hpp>
#include <tg/types/input_message_content.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultArticle Parse(const Value& value,
                               To<InlineQueryResultArticle>) {
    InlineQueryResultArticle obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.input_message_content =
        ParseComplex<InputMessageContent>(value["input_message_content"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.url = ParseComplex<Optional<String>>(value["url"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.thumbnail_url = ParseComplex<Optional<String>>(value["thumbnail_url"]);
    obj.thumbnail_width =
        ParseComplex<Optional<Integer>>(value["thumbnail_width"]);
    obj.thumbnail_height =
        ParseComplex<Optional<Integer>>(value["thumbnail_height"]);
    return obj;
}

}  // namespace tg
