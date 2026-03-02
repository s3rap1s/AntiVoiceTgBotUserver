#include <types/message_origin.hpp>
#include <types/message_origin_channel.hpp>
#include <types/message_origin_chat.hpp>
#include <types/message_origin_hidden_user.hpp>
#include <types/message_origin_user.hpp>

#include "common.hpp"

namespace tg {

MessageOrigin Parse(const Value& value, To<MessageOrigin>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "user") return ParseComplex<MessageOriginUser>(value);
    if (type == "hidden_user")
        return ParseComplex<MessageOriginHiddenUser>(value);
    if (type == "chat") return ParseComplex<MessageOriginChat>(value);
    if (type == "channel") return ParseComplex<MessageOriginChannel>(value);
    throw std::runtime_error("Unknown MessageOrigin type: " + type);
}

}  // namespace tg
