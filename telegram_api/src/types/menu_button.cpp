#include <tg/types/menu_button.hpp>
#include <tg/types/menu_button_commands.hpp>
#include <tg/types/menu_button_default.hpp>
#include <tg/types/menu_button_web_app.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MenuButton Parse(const Value& value, To<MenuButton>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "commands") return ParseComplex<MenuButtonCommands>(value);
    if (type == "web_app") return ParseComplex<MenuButtonWebApp>(value);
    if (type == "default") return ParseComplex<MenuButtonDefault>(value);
    throw std::runtime_error("Unknown MenuButton type: " + type);
}

void Serialize(const MenuButton& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
