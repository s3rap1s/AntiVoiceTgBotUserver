#include <tg/types/location_address.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const LocationAddress& obj, ValueBuilder& builder) {
    internal::Put(builder, "country_code", obj.country_code);
    internal::Put(builder, "state", obj.state);
    internal::Put(builder, "city", obj.city);
    internal::Put(builder, "street", obj.street);
}

}  // namespace tg
