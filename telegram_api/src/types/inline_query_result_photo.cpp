#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_photo.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
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
    obj.caption_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media = ParseComplex<Optional<Boolean>>(value["show_caption_above_media"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(value["input_message_content"]);
    return obj;
}

void Serialize(const InlineQueryResultPhoto& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "photo_url", obj.photo_url);
    internal::Put(builder, "thumbnail_url", obj.thumbnail_url);
    internal::Put(builder, "photo_width", obj.photo_width);
    internal::Put(builder, "photo_height", obj.photo_height);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "description", obj.description);
    internal::Put(builder, "caption", obj.caption);
    internal::Put(builder, "parse_mode", obj.parse_mode);
    internal::Put(builder, "caption_entities", obj.caption_entities);
    internal::Put(builder, "show_caption_above_media", obj.show_caption_above_media);
    internal::Put(builder, "reply_markup", obj.reply_markup);
    internal::Put(builder, "input_message_content", obj.input_message_content);
}

}  // namespace tg
