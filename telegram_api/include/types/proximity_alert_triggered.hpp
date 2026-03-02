#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct ProximityAlertTriggered {
    User traveler;
    User watcher;
    Integer distance;
};

ProximityAlertTriggered Parse(const Value& value, To<ProximityAlertTriggered>);

}  // namespace tg
