#include <types/inline_keyboard_markup.hpp>
#include <types/inline_query_result_mpeg_4_gif.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultMpeg4Gif Parse(const Value& value,
                                To<InlineQueryResultMpeg4Gif>) {
    InlineQueryResultMpeg4Gif obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.mpeg4_url = ParseComplex<String>(value["mpeg4_url"]);
    obj.mpeg4_width = ParseComplex<Optional<Integer>>(value["mpeg4_width"]);
    obj.mpeg4_height = ParseComplex<Optional<Integer>>(value["mpeg4_height"]);
    obj.mpeg4_duration =
        ParseComplex<Optional<Integer>>(value["mpeg4_duration"]);
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
