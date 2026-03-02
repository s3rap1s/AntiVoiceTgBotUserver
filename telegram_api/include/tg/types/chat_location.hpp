#pragma once

#include <tg/types/common.hpp>
#include <tg/types/location.hpp>

namespace tg {

struct ChatLocation {
    Location location;
    String address;
};

ChatLocation Parse(const Value& value, To<ChatLocation>);

}  // namespace tg
