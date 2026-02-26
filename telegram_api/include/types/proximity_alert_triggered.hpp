#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct ProximityAlertTriggered {
    User traveler;
    User watcher;
    Integer distance;
};

ProximityAlertTriggered Parse(const Value& value, To<ProximityAlertTriggered>);

}  // namespace tg
