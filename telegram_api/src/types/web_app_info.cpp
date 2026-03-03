#include <tg/types/web_app_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

WebAppInfo Parse(const Value& value, To<WebAppInfo>) {
    WebAppInfo obj{};
    obj.url = ParseComplex<String>(value["url"]);
    return obj;
}

void Serialize(const WebAppInfo& obj, ValueBuilder& builder) { internal::Put(builder, "url", obj.url); }

}  // namespace tg
