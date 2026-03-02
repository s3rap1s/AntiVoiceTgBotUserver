#include <types/inline_keyboard_markup.hpp>
#include <types/inline_query_result_video.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultVideo Parse(const Value& value, To<InlineQueryResultVideo>) {
    InlineQueryResultVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.video_url = ParseComplex<String>(value["video_url"]);
    obj.mime_type = ParseComplex<String>(value["mime_type"]);
    obj.thumbnail_url = ParseComplex<String>(value["thumbnail_url"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media =
        ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.video_width = ParseComplex<Optional<Integer>>(value["video_width"]);
    obj.video_height = ParseComplex<Optional<Integer>>(value["video_height"]);
    obj.video_duration =
        ParseComplex<Optional<Integer>>(value["video_duration"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    return obj;
}

}  // namespace tg
