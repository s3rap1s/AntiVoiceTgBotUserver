#pragma once

#include <types/common.hpp>
#include <types/menu_button_commands.hpp>
#include <types/menu_button_default.hpp>
#include <types/menu_button_web_app.hpp>

namespace tg {

using MenuButton =
    OneOf<MenuButtonCommands, MenuButtonWebApp, MenuButtonDefault>;

MenuButton Parse(const Value& value, To<MenuButton>);

}  // namespace tg
