#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_audio.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultAudio Parse(const Value& value, To<InlineQueryResultAudio>) {
    InlineQueryResultAudio obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.audio_url = ParseComplex<String>(value["audio_url"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.performer = ParseComplex<Optional<String>>(value["performer"]);
    obj.audio_duration =
        ParseComplex<Optional<Integer>>(value["audio_duration"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    return obj;
}

}  // namespace tg
