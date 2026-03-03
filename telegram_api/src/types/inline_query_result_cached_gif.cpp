#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_cached_gif.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultCachedGif Parse(const Value& value, To<InlineQueryResultCachedGif>) {
    InlineQueryResultCachedGif obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.gif_file_id = ParseComplex<String>(value["gif_file_id"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.parse_mode = ParseComplex<Optional<String>>(value["parse_mode"]);
    obj.caption_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media = ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(value["input_message_content"]);
    return obj;
}

void Serialize(const InlineQueryResultCachedGif& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "gif_file_id", obj.gif_file_id);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "caption", obj.caption);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "caption_entities", obj.caption_entities);
    internal::Put(builder, "show_caption_above_media", obj.show_caption_above_media);
    internal::Put(builder, "reply_markup", obj.reply_markup);
    internal::Put(builder, "input_message_content", obj.input_message_content);
}

}  // namespace tg
