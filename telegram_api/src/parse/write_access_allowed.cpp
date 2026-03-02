#include <tg/types/write_access_allowed.hpp>

#include "common.hpp"

namespace tg {

WriteAccessAllowed Parse(const Value& value, To<WriteAccessAllowed>) {
    WriteAccessAllowed obj{};
    obj.from_request = ParseComplex<Optional<Boolean>>(value["from_request"]);
    obj.web_app_name = ParseComplex<Optional<String>>(value["web_app_name"]);
    obj.from_attachment_menu =
        ParseComplex<Optional<Boolean>>(value["from_attachment_menu"]);
    return obj;
}

}  // namespace tg
