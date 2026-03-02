#include <tg/types/location_address.hpp>

#include "common.hpp"

namespace tg {

LocationAddress Parse(const Value& value, To<LocationAddress>) {
    LocationAddress obj{};
    obj.country_code = ParseComplex<String>(value["country_code"]);
    obj.state = ParseComplex<Optional<String>>(value["state"]);
    obj.city = ParseComplex<Optional<String>>(value["city"]);
    obj.street = ParseComplex<Optional<String>>(value["street"]);
    return obj;
}

}  // namespace tg
