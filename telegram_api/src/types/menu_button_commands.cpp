#include <tg/types/menu_button_commands.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MenuButtonCommands Parse(const Value& value, To<MenuButtonCommands>) {
    MenuButtonCommands obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const MenuButtonCommands& obj, ValueBuilder& builder) { internal::Put(builder, "type", obj.type); }

}  // namespace tg
