#include <types/menu_button_web_app.hpp>
#include <types/web_app_info.hpp>

#include "common.hpp"

namespace tg {

MenuButtonWebApp Parse(const Value& value, To<MenuButtonWebApp>) {
    MenuButtonWebApp obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.text = ParseComplex<String>(value["text"]);
    obj.web_app = ParseComplex<WebAppInfo>(value["web_app"]);
    return obj;
}

}  // namespace tg
