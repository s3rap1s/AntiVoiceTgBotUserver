#include <tg/types/bot_command_scope_default.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotCommandScopeDefault Parse(const Value& value, To<BotCommandScopeDefault>) {
    BotCommandScopeDefault obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const BotCommandScopeDefault& obj, ValueBuilder& builder) { internal::Put(builder, "type", obj.type); }

}  // namespace tg
