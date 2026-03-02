#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_markup.hpp>
#include <types/input_message_content.hpp>

namespace tg {

struct InlineQueryResultVenue {
    String type;
    String id;
    Float latitude;
    Float longitude;
    String title;
    String address;
    Optional<String> foursquare_id;
    Optional<String> foursquare_type;
    Optional<String> google_place_id;
    Optional<String> google_place_type;
    Optional<InlineKeyboardMarkup> reply_markup;
    Optional<InputMessageContent> input_message_content;
    Optional<String> thumbnail_url;
    Optional<Integer> thumbnail_width;
    Optional<Integer> thumbnail_height;
};

InlineQueryResultVenue Parse(const Value& value, To<InlineQueryResultVenue>);

}  // namespace tg
