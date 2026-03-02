#pragma once

#include <types/common.hpp>
#include <types/location.hpp>

namespace tg {

struct BusinessLocation {
    String address;
    Optional<Location> location;
};

BusinessLocation Parse(const Value& value, To<BusinessLocation>);

}  // namespace tg
