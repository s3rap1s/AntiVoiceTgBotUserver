#include <tg/types/bot_description.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotDescription Parse(const Value& value, To<BotDescription>) {
    BotDescription obj{};
    obj.description = ParseComplex<String>(value["description"]);
    return obj;
}

void Serialize(const BotDescription& obj, ValueBuilder& builder) {
    internal::Put(builder, "description", obj.description);
}

}  // namespace tg
