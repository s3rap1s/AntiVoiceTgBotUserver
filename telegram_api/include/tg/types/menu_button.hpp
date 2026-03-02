#pragma once

#include <tg/types/common.hpp>
#include <tg/types/menu_button_commands.hpp>
#include <tg/types/menu_button_default.hpp>
#include <tg/types/menu_button_web_app.hpp>

namespace tg {

using MenuButton =
    OneOf<MenuButtonCommands, MenuButtonWebApp, MenuButtonDefault>;

MenuButton Parse(const Value& value, To<MenuButton>);

}  // namespace tg
