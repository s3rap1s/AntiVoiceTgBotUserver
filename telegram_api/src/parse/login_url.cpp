#include <types/login_url.hpp>

#include "common.hpp"

namespace tg {

LoginUrl Parse(const Value& value, To<LoginUrl>) {
    LoginUrl obj{};
    obj.url = ParseComplex<String>(value["url"]);
    obj.forward_text = ParseComplex<Optional<String>>(value["forward_text"]);
    obj.bot_username = ParseComplex<Optional<String>>(value["bot_username"]);
    obj.request_write_access =
        ParseComplex<Optional<Boolean>>(value["request_write_access"]);
    return obj;
}

}  // namespace tg
