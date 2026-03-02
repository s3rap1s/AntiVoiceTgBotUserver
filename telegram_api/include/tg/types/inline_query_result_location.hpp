#pragma once

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultLocation {
    String type;
    String id;
    Float latitude;
    Float longitude;
    String title;
    Optional<Float> horizontal_accuracy;
    Optional<Integer> live_period;
    Optional<Integer> heading;
    Optional<Integer> proximity_alert_radius;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
    Optional<String> thumbnail_url;
    Optional<Integer> thumbnail_width;
    Optional<Integer> thumbnail_height;
};

InlineQueryResultLocation Parse(const Value& value,
                                To<InlineQueryResultLocation>);

}  // namespace tg
