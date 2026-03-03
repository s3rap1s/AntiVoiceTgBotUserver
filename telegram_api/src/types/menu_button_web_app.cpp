#include <tg/types/menu_button_web_app.hpp>
#include <tg/types/web_app_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

MenuButtonWebApp Parse(const Value& value, To<MenuButtonWebApp>) {
    MenuButtonWebApp obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.text = ParseComplex<String>(value["text"]);
    obj.web_app = ParseComplex<WebAppInfo>(value["web_app"]);
    return obj;
}

void Serialize(const MenuButtonWebApp& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "web_app", obj.web_app);
}

}  // namespace tg
