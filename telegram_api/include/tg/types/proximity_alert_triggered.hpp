#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ProximityAlertTriggered {
    User traveler;
    User watcher;
    Integer distance;
};

ProximityAlertTriggered Parse(const Value& value, To<ProximityAlertTriggered>);

}  // namespace tg
