#include <types/inline_keyboard_markup.hpp>
#include <types/inline_query_result_cached_gif.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultCachedGif Parse(const Value& value,
                                 To<InlineQueryResultCachedGif>) {
    InlineQueryResultCachedGif obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.gif_file_id = ParseComplex<String>(value["gif_file_id"]);
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
