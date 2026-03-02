#include <tg/types/proximity_alert_triggered.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ProximityAlertTriggered Parse(const Value& value, To<ProximityAlertTriggered>) {
    ProximityAlertTriggered obj{};
    obj.traveler = ParseComplex<User>(value["traveler"]);
    obj.watcher = ParseComplex<User>(value["watcher"]);
    obj.distance = ParseComplex<Integer>(value["distance"]);
    return obj;
}

}  // namespace tg
