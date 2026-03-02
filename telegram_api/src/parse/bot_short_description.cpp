#include <tg/types/bot_short_description.hpp>

#include "common.hpp"

namespace tg {

BotShortDescription Parse(const Value& value, To<BotShortDescription>) {
    BotShortDescription obj{};
    obj.short_description = ParseComplex<String>(value["short_description"]);
    return obj;
}

}  // namespace tg
