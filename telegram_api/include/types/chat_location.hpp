#pragma once

#include "common.hpp"
#include "location.hpp"

namespace tg {

struct ChatLocation {
    Location location;
    String address;
};

ChatLocation Parse(const Value& value, To<ChatLocation>);

}  // namespace tg
