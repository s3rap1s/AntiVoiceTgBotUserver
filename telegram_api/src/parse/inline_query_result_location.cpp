#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_location.hpp>
#include <tg/types/input_message_content.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultLocation Parse(const Value& value,
                                To<InlineQueryResultLocation>) {
    InlineQueryResultLocation obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.latitude = ParseComplex<Float>(value["latitude"]);
    obj.longitude = ParseComplex<Float>(value["longitude"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.horizontal_accuracy =
        ParseComplex<Optional<Float>>(value["horizontal_accuracy"]);
    obj.live_period = ParseComplex<Optional<Integer>>(value["live_period"]);
    obj.heading = ParseComplex<Optional<Integer>>(value["heading"]);
    obj.proximity_alert_radius =
        ParseComplex<Optional<Integer>>(value["proximity_alert_radius"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    obj.input_message_content = ParseComplex<Optional<InputMessageContent>>(
        value["input_message_content"]);
    obj.thumbnail_url = ParseComplex<Optional<String>>(value["thumbnail_url"]);
    obj.thumbnail_width =
        ParseComplex<Optional<Integer>>(value["thumbnail_width"]);
    obj.thumbnail_height =
        ParseComplex<Optional<Integer>>(value["thumbnail_height"]);
    return obj;
}

}  // namespace tg
