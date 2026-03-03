#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/location.hpp>

namespace tg {

struct BusinessLocation {
    String address;
    Optional<Location> location;
};

BusinessLocation Parse(const Value& value, To<BusinessLocation>);

void Serialize(const BusinessLocation& obj, ValueBuilder& builder);

}  // namespace tg
