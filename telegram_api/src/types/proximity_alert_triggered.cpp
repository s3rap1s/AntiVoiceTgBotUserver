#include <tg/types/proximity_alert_triggered.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ProximityAlertTriggered Parse(const Value& value, To<ProximityAlertTriggered>) {
    ProximityAlertTriggered obj{};
    obj.traveler = ParseComplex<User>(value["traveler"]);
    obj.watcher = ParseComplex<User>(value["watcher"]);
    obj.distance = ParseComplex<Integer>(value["distance"]);
    return obj;
}

void Serialize(const ProximityAlertTriggered& obj, ValueBuilder& builder) {
    internal::Put(builder, "traveler", obj.traveler);
    internal::Put(builder, "watcher", obj.watcher);
    internal::Put(builder, "distance", obj.distance);
}

}  // namespace tg
