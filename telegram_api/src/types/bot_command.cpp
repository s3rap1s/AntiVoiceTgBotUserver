#include <tg/types/bot_command.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommand Parse(const Value& value, To<BotCommand>) {
    BotCommand obj{};
    obj.command = ParseComplex<String>(value["command"]);
    obj.description = ParseComplex<String>(value["description"]);
    return obj;
}

void Serialize(const BotCommand& obj, ValueBuilder& builder) {
    internal::Put(builder, "command", obj.command);
    internal::Put(builder, "description", obj.description);
}

}  // namespace tg
