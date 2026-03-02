#pragma once

#include <types/common.hpp>

namespace tg {

struct LocationAddress {
    String country_code;
    Optional<String> state;
    Optional<String> city;
    Optional<String> street;
};

LocationAddress Parse(const Value& value, To<LocationAddress>);

}  // namespace tg
