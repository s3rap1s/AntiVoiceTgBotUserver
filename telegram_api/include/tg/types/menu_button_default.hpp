#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct MenuButtonDefault {
    String type;
};

MenuButtonDefault Parse(const Value& value, To<MenuButtonDefault>);

void Serialize(const MenuButtonDefault& obj, ValueBuilder& builder);

}  // namespace tg
