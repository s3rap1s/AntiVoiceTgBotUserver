#pragma once

#include "common.hpp"
#include "web_app_info.hpp"

namespace tg {

struct MenuButtonWebApp {
    String type;
    String text;
    WebAppInfo web_app;
};

MenuButtonWebApp Parse(const Value& value, To<MenuButtonWebApp>);

}  // namespace tg
