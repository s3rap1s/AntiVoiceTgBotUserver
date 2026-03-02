#include <types/menu_button_commands.hpp>

#include "common.hpp"

namespace tg {

MenuButtonCommands Parse(const Value& value, To<MenuButtonCommands>) {
    MenuButtonCommands obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
