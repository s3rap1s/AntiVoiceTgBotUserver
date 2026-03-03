#include <tg/types/location_address.hpp>
#include <tg/types/story_area_type_location.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const StoryAreaTypeLocation& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "latitude", obj.latitude);
    internal::Put(builder, "longitude", obj.longitude);
    internal::Put(builder, "address", obj.address);
}

}  // namespace tg
