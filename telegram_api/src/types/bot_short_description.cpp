#include <tg/types/bot_short_description.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BotShortDescription Parse(const Value& value, To<BotShortDescription>) {
    BotShortDescription obj{};
    obj.short_description = ParseComplex<String>(value["short_description"]);
    return obj;
}

void Serialize(const BotShortDescription& obj, ValueBuilder& builder) {
    internal::Put(builder, "short_description", obj.short_description);
}

}  // namespace tg
