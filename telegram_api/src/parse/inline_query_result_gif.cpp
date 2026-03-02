#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_gif.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultGif Parse(const Value& value, To<InlineQueryResultGif>) {
    InlineQueryResultGif obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.gif_url = ParseComplex<String>(value["gif_url"]);
    obj.gif_width = ParseComplex<Optional<Integer>>(value["gif_width"]);
    obj.gif_height = ParseComplex<Optional<Integer>>(value["gif_height"]);
    obj.gif_duration = ParseComplex<Optional<Integer>>(value["gif_duration"]);
    obj.thumbnail_url = ParseComplex<String>(value["thumbnail_url"]);
    obj.thumbnail_mime_type =
        ParseComplex<Optional<String>>(value["thumbnail_mime_type"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media =
        ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    return obj;
}

}  // namespace tg
