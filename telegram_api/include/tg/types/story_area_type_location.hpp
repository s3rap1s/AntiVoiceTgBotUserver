#pragma once

#include <userver/formats/json/value_builder.hpp>

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

void Serialize(const StoryAreaTypeLocation& obj, ValueBuilder& builder);

}  // namespace tg
