#include <types/business_location.hpp>
#include <types/location.hpp>

#include "common.hpp"

namespace tg {

BusinessLocation Parse(const Value& value, To<BusinessLocation>) {
    BusinessLocation obj{};
    obj.address = ParseComplex<String>(value["address"]);
    obj.location = ParseComplex<Optional<Location>>(value["location"]);
    return obj;
}

}  // namespace tg
