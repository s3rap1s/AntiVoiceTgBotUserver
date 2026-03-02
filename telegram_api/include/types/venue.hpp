#pragma once

#include <types/common.hpp>
#include <types/location.hpp>

namespace tg {

struct Venue {
    Location location;
    String title;
    String address;
    Optional<String> foursquare_id;
    Optional<String> foursquare_type;
    Optional<String> google_place_id;
    Optional<String> google_place_type;
};

Venue Parse(const Value& value, To<Venue>);

}  // namespace tg
