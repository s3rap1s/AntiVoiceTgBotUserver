#pragma once

#include "common.hpp"

namespace tg {

struct InputLocationMessageContent {
    Float latitude;
    Float longitude;
    Optional<String> horizontal_accuracy;
    Optional<Integer> live_period;
    Optional<Integer> heading;
    Optional<Integer> proximity_alert_radius;
};

InputLocationMessageContent Parse(const Value& value,
                                  To<InputLocationMessageContent>);

}  // namespace tg
