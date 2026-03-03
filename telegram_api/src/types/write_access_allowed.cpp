#include <tg/types/write_access_allowed.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

WriteAccessAllowed Parse(const Value& value, To<WriteAccessAllowed>) {
    WriteAccessAllowed obj{};
    obj.from_request = ParseComplex<Optional<Boolean>>(value["from_request"]);
    obj.web_app_name = ParseComplex<Optional<String>>(value["web_app_name"]);
    obj.from_attachment_menu = ParseComplex<Optional<Boolean>>(value["from_attachment_menu"]);
    return obj;
}

void Serialize(const WriteAccessAllowed& obj, ValueBuilder& builder) {
    internal::Put(builder, "from_request", obj.from_request);
    internal::Put(builder, "web_app_name", obj.web_app_name);
    internal::Put(builder, "from_attachment_menu", obj.from_attachment_menu);
}

}  // namespace tg
