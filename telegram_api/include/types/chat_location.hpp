#pragma once

#include <types/common.hpp>
#include <types/location.hpp>

namespace tg {

struct ChatLocation {
    Location location;
    String address;
};

ChatLocation Parse(const Value& value, To<ChatLocation>);

}  // namespace tg
