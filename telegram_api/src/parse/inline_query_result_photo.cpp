#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_photo.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultPhoto Parse(const Value& value, To<InlineQueryResultPhoto>) {
    InlineQueryResultPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.photo_url = ParseComplex<String>(value["photo_url"]);
    obj.thumbnail_url = ParseComplex<String>(value["thumbnail_url"]);
    obj.photo_width = ParseComplex<Optional<Integer>>(value["photo_width"]);
    obj.photo_height = ParseComplex<Optional<Integer>>(value["photo_height"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
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
