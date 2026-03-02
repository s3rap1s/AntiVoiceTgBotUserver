#include <tg/types/location.hpp>
#include <tg/types/venue.hpp>

#include "common.hpp"

namespace tg {

Venue Parse(const Value& value, To<Venue>) {
    Venue obj{};
    obj.location = ParseComplex<Location>(value["location"]);
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
