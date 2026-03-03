#include <tg/types/menu_button_default.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MenuButtonDefault Parse(const Value& value, To<MenuButtonDefault>) {
    MenuButtonDefault obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const MenuButtonDefault& obj, ValueBuilder& builder) { internal::Put(builder, "type", obj.type); }

}  // namespace tg
