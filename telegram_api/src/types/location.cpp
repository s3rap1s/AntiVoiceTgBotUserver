#include <tg/types/location.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Location Parse(const Value& value, To<Location>) {
    Location obj{};
    obj.latitude = ParseComplex<Float>(value["latitude"]);
    obj.longitude = ParseComplex<Float>(value["longitude"]);
    obj.horizontal_accuracy = ParseComplex<Optional<Float>>(value["horizontal_accuracy"]);
    obj.live_period = ParseComplex<Optional<Integer>>(value["live_period"]);
    obj.heading = ParseComplex<Optional<Integer>>(value["heading"]);
    obj.proximity_alert_radius = ParseComplex<Optional<Integer>>(value["proximity_alert_radius"]);
    return obj;
}

void Serialize(const Location& obj, ValueBuilder& builder) {
    internal::Put(builder, "latitude", obj.latitude);
    internal::Put(builder, "longitude", obj.longitude);
    internal::Put(builder, "horizontal_accuracy", obj.horizontal_accuracy);
    internal::Put(builder, "live_period", obj.live_period);
    internal::Put(builder, "heading", obj.heading);
    internal::Put(builder, "proximity_alert_radius", obj.proximity_alert_radius);
}

}  // namespace tg
