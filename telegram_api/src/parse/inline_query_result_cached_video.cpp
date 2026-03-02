#include <types/inline_keyboard_markup.hpp>
#include <types/inline_query_result_cached_video.hpp>
#include <types/input_message_content.hpp>
#include <types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultCachedVideo Parse(const Value& value,
                                   To<InlineQueryResultCachedVideo>) {
    InlineQueryResultCachedVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.video_file_id = ParseComplex<String>(value["video_file_id"]);
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
