#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_contact.hpp>
#include <tg/types/input_message_content.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultContact Parse(const Value& value, To<InlineQueryResultContact>) {
    InlineQueryResultContact obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.phone_number = ParseComplex<String>(value["phone_number"]);
    obj.first_name = ParseComplex<String>(value["first_name"]);
    obj.last_name = ParseComplex<Optional<String>>(value["last_name"]);
    obj.vcard = ParseComplex<Optional<String>>(value["vcard"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(value["input_message_content"]);
    obj.thumbnail_url = ParseComplex<Optional<String>>(value["thumbnail_url"]);
    obj.thumbnail_width = ParseComplex<Optional<Integer>>(value["thumbnail_width"]);
    obj.thumbnail_height = ParseComplex<Optional<Integer>>(value["thumbnail_height"]);
    return obj;
}

void Serialize(const InlineQueryResultContact& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "phone_number", obj.phone_number);
    internal::Put(builder, "first_name", obj.first_name);
    internal::Put(builder, "last_name", obj.last_name);
    internal::Put(builder, "vcard", obj.vcard);
    internal::Put(builder, "reply_markup", obj.reply_markup);
    internal::Put(builder, "input_message_content", obj.input_message_content);
    internal::Put(builder, "thumbnail_url", obj.thumbnail_url);
    internal::Put(builder, "thumbnail_width", obj.thumbnail_width);
    internal::Put(builder, "thumbnail_height", obj.thumbnail_height);
}

}  // namespace tg
