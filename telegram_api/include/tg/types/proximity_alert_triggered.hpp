#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ProximityAlertTriggered {
    User traveler;
    User watcher;
    Integer distance;
};

ProximityAlertTriggered Parse(const Value& value, To<ProximityAlertTriggered>);

void Serialize(const ProximityAlertTriggered& obj, ValueBuilder& builder);

}  // namespace tg
