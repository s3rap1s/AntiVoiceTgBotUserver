#include <tg/types/bot_name.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotName Parse(const Value& value, To<BotName>) {
    BotName obj{};
    obj.name = ParseComplex<String>(value["name"]);
    return obj;
}

void Serialize(const BotName& obj, ValueBuilder& builder) { internal::Put(builder, "name", obj.name); }

}  // namespace tg
