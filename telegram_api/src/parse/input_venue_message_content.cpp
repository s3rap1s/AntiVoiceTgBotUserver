#include <types/input_venue_message_content.hpp>

#include "common.hpp"

namespace tg {

InputVenueMessageContent Parse(const Value& value,
                               To<InputVenueMessageContent>) {
    InputVenueMessageContent obj{};
    obj.latitude = ParseComplex<Float>(value["latitude"]);
    obj.longitude = ParseComplex<Float>(value["longitude"]);
    obj.title = ParseComplex<String>(value["title"]);
    obj.address = ParseComplex<String>(value["address"]);
    obj.foursquare_id = ParseComplex<Optional<String>>(value["foursquare_id"]);
    obj.foursquare_type =
        ParseComplex<Optional<String>>(value["foursquare_type"]);
    obj.google_place_id =
        ParseComplex<Optional<String>>(value["google_place_id"]);
    obj.google_place_type =
        ParseComplex<Optional<String>>(value["google_place_type"]);
    return obj;
}

}  // namespace tg
