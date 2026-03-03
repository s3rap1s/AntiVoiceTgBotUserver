#include <tg/types/sent_web_app_message.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SentWebAppMessage Parse(const Value& value, To<SentWebAppMessage>) {
    SentWebAppMessage obj{};
    obj.inline_message_id = ParseComplex<Optional<String>>(value["inline_message_id"]);
    return obj;
}

void Serialize(const SentWebAppMessage& obj, ValueBuilder& builder) {
    internal::Put(builder, "inline_message_id", obj.inline_message_id);
}

}  // namespace tg
