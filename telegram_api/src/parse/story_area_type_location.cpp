#include <tg/types/location_address.hpp>
#include <tg/types/story_area_type_location.hpp>

#include "common.hpp"

namespace tg {

StoryAreaTypeLocation Parse(const Value& value, To<StoryAreaTypeLocation>) {
    StoryAreaTypeLocation obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.latitude = ParseComplex<Float>(value["latitude"]);
    obj.longitude = ParseComplex<Float>(value["longitude"]);
    obj.address = ParseComplex<Optional<LocationAddress>>(value["address"]);
    return obj;
}

}  // namespace tg
