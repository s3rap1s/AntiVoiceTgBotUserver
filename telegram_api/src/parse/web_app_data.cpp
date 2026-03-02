#include <tg/types/web_app_data.hpp>

#include "common.hpp"

namespace tg {

WebAppData Parse(const Value& value, To<WebAppData>) {
    WebAppData obj{};
    obj.data = ParseComplex<String>(value["data"]);
    obj.button_text = ParseComplex<String>(value["button_text"]);
    return obj;
}

}  // namespace tg
