#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/location.hpp>

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

void Serialize(const Venue& obj, ValueBuilder& builder);

}  // namespace tg
