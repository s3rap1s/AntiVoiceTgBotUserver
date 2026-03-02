#include <tg/types/sent_web_app_message.hpp>

#include "common.hpp"

namespace tg {

SentWebAppMessage Parse(const Value& value, To<SentWebAppMessage>) {
    SentWebAppMessage obj{};
    obj.inline_message_id =
        ParseComplex<Optional<String>>(value["inline_message_id"]);
    return obj;
}

}  // namespace tg
