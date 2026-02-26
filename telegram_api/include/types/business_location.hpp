#pragma once

#include "common.hpp"
#include "location.hpp"

namespace tg {

struct BusinessLocation {
    String address;
    Optional<Location> location;
};

BusinessLocation Parse(const Value& value, To<BusinessLocation>);

}  // namespace tg
