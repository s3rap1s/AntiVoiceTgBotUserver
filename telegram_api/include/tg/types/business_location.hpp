#pragma once

#include <tg/types/common.hpp>
#include <tg/types/location.hpp>

namespace tg {

struct BusinessLocation {
    String address;
    Optional<Location> location;
};

BusinessLocation Parse(const Value& value, To<BusinessLocation>);

}  // namespace tg
