#include <tg/types/input_location_message_content.hpp>

#include "common.hpp"

namespace tg {

InputLocationMessageContent Parse(const Value& value,
                                  To<InputLocationMessageContent>) {
    InputLocationMessageContent obj{};
    obj.latitude = ParseComplex<Float>(value["latitude"]);
    obj.longitude = ParseComplex<Float>(value["longitude"]);
    obj.horizontal_accuracy =
        ParseComplex<Optional<String>>(value["horizontal_accuracy"]);
    obj.live_period = ParseComplex<Optional<Integer>>(value["live_period"]);
    obj.heading = ParseComplex<Optional<Integer>>(value["heading"]);
    obj.proximity_alert_radius =
        ParseComplex<Optional<Integer>>(value["proximity_alert_radius"]);
    return obj;
}

}  // namespace tg
