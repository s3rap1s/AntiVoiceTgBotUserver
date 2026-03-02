#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_voice.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultVoice Parse(const Value& value, To<InlineQueryResultVoice>) {
    InlineQueryResultVoice obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.voice_url = ParseComplex<String>(value["voice_url"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.voice_duration =
        ParseComplex<Optional<Integer>>(value["voice_duration"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    return obj;
}

}  // namespace tg
