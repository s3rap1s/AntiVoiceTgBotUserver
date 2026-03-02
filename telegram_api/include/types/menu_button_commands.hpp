#pragma once

#include <types/common.hpp>

namespace tg {

struct MenuButtonCommands {
    String type;
};

MenuButtonCommands Parse(const Value& value, To<MenuButtonCommands>);

}  // namespace tg
