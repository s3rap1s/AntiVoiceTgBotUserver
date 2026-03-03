#include <tg/types/business_location.hpp>
#include <tg/types/location.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BusinessLocation Parse(const Value& value, To<BusinessLocation>) {
    BusinessLocation obj{};
    obj.address = ParseComplex<String>(value["address"]);
    obj.location = ParseComplex<Optional<Location>>(value["location"]);
    return obj;
}

void Serialize(const BusinessLocation& obj, ValueBuilder& builder) {
    internal::Put(builder, "address", obj.address);
    internal::Put(builder, "location", obj.location);
}

}  // namespace tg
