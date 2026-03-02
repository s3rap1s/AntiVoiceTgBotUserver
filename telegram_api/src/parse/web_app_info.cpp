#include <tg/types/web_app_info.hpp>

#include "common.hpp"

namespace tg {

WebAppInfo Parse(const Value& value, To<WebAppInfo>) {
    WebAppInfo obj{};
    obj.url = ParseComplex<String>(value["url"]);
    return obj;
}

}  // namespace tg
