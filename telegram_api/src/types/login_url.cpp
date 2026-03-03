#include <tg/types/login_url.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

LoginUrl Parse(const Value& value, To<LoginUrl>) {
    LoginUrl obj{};
    obj.url = ParseComplex<String>(value["url"]);
    obj.forward_text = ParseComplex<Optional<String>>(value["forward_text"]);
    obj.bot_username = ParseComplex<Optional<String>>(value["bot_username"]);
    obj.request_write_access = ParseComplex<Optional<Boolean>>(value["request_write_access"]);
    return obj;
}

void Serialize(const LoginUrl& obj, ValueBuilder& builder) {
    internal::Put(builder, "url", obj.url);
    internal::Put(builder, "forward_text", obj.forward_text);
    internal::Put(builder, "bot_username", obj.bot_username);
    internal::Put(builder, "request_write_access", obj.request_write_access);
}

}  // namespace tg
