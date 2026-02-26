#pragma once

#include "common.hpp"

namespace tg {

struct MenuButtonDefault {
    String type;
};

MenuButtonDefault Parse(const Value& value, To<MenuButtonDefault>);

}  // namespace tg
