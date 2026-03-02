#include <tg/types/location.hpp>

#include "common.hpp"

namespace tg {

Location Parse(const Value& value, To<Location>) {
    Location obj{};
    obj.latitude = ParseComplex<Float>(value["latitude"]);
    obj.longitude = ParseComplex<Float>(value["longitude"]);
    obj.horizontal_accuracy =
        ParseComplex<Optional<Float>>(value["horizontal_accuracy"]);
    obj.live_period = ParseComplex<Optional<Integer>>(value["live_period"]);
    obj.heading = ParseComplex<Optional<Integer>>(value["heading"]);
    obj.proximity_alert_radius =
        ParseComplex<Optional<Integer>>(value["proximity_alert_radius"]);
    return obj;
}

}  // namespace tg
