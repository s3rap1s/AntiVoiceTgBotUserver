#pragma once

#include "common.hpp"
#include "menu_button_commands.hpp"
#include "menu_button_default.hpp"
#include "menu_button_web_app.hpp"

namespace tg {

using MenuButton =
    OneOf<MenuButtonCommands, MenuButtonWebApp, MenuButtonDefault>;

MenuButton Parse(const Value& value, To<MenuButton>);

}  // namespace tg
