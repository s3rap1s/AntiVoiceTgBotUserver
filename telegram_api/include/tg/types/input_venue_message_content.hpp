#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct InputVenueMessageContent {
    Float latitude;
    Float longitude;
    String title;
    String address;
    Optional<String> foursquare_id;
    Optional<String> foursquare_type;
    Optional<String> google_place_id;
    Optional<String> google_place_type;
};

InputVenueMessageContent Parse(const Value& value,
                               To<InputVenueMessageContent>);

}  // namespace tg
