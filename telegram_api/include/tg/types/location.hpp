#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct Location {
    Float latitude;
    Float longitude;
    Optional<Float> horizontal_accuracy;
    Optional<Integer> live_period;
    Optional<Integer> heading;
    Optional<Integer> proximity_alert_radius;
};

Location Parse(const Value& value, To<Location>);

}  // namespace tg
