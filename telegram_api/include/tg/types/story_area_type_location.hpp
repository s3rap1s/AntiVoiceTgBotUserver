#pragma once

#include <tg/types/common.hpp>
#include <tg/types/location_address.hpp>

namespace tg {

struct StoryAreaTypeLocation {
    String type;
    Float latitude;
    Float longitude;
    Optional<LocationAddress> address;
};

StoryAreaTypeLocation Parse(const Value& value, To<StoryAreaTypeLocation>);

}  // namespace tg
