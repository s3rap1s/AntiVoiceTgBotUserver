#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct LocationAddress {
    String country_code;
    Optional<String> state;
    Optional<String> city;
    Optional<String> street;
};

LocationAddress Parse(const Value& value, To<LocationAddress>);

void Serialize(const LocationAddress& obj, ValueBuilder& builder);

}  // namespace tg
