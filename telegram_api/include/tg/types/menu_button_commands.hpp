#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct MenuButtonCommands {
    String type;
};

MenuButtonCommands Parse(const Value& value, To<MenuButtonCommands>);

void Serialize(const MenuButtonCommands& obj, ValueBuilder& builder);

}  // namespace tg
