#include <types/menu_button_default.hpp>

#include "common.hpp"

namespace tg {

MenuButtonDefault Parse(const Value& value, To<MenuButtonDefault>) {
    MenuButtonDefault obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
