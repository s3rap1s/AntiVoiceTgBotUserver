#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/web_app_info.hpp>

namespace tg {

struct MenuButtonWebApp {
    String type;
    String text;
    WebAppInfo web_app;
};

MenuButtonWebApp Parse(const Value& value, To<MenuButtonWebApp>);

void Serialize(const MenuButtonWebApp& obj, ValueBuilder& builder);

}  // namespace tg
