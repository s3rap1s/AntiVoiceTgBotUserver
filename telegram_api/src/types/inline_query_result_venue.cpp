#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_venue.hpp>
#include <tg/types/input_message_content.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultVenue Parse(const Value& value, To<InlineQueryResultVenue>) {
    InlineQueryResultVenue obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.latitude = ParseComplex<Float>(value["latitude"]);
    obj.longitude = ParseComplex<Float>(value["longitude"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.address = ParseComplex<String>(value["address"]);
    obj.foursquare_id = ParseComplex<Optional<String>>(value["foursquare_id"]);
    obj.foursquare_type = ParseComplex<Optional<String>>(value["foursquare_type"]);
    obj.google_place_id = ParseComplex<Optional<String>>(value["google_place_id"]);
    obj.google_place_type = ParseComplex<Optional<String>>(value["google_place_type"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(value["input_message_content"]);
    obj.thumbnail_url = ParseComplex<Optional<String>>(value["thumbnail_url"]);
    obj.thumbnail_width = ParseComplex<Optional<Integer>>(value["thumbnail_width"]);
    obj.thumbnail_height = ParseComplex<Optional<Integer>>(value["thumbnail_height"]);
    return obj;
}

void Serialize(const InlineQueryResultVenue& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "latitude", obj.latitude);
    internal::Put(builder, "longitude", obj.longitude);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "address", obj.address);
    internal::Put(builder, "foursquare_id", obj.foursquare_id);
    internal::Put(builder, "foursquare_type", obj.foursquare_type);
    internal::Put(builder, "google_place_id", obj.google_place_id);
    internal::Put(builder, "google_place_type", obj.google_place_type);
    internal::Put(builder, "reply_markup", obj.reply_markup);
    internal::Put(builder, "input_message_content", obj.input_message_content);
    internal::Put(builder, "thumbnail_url", obj.thumbnail_url);
    internal::Put(builder, "thumbnail_width", obj.thumbnail_width);
    internal::Put(builder, "thumbnail_height", obj.thumbnail_height);
}

}  // namespace tg
