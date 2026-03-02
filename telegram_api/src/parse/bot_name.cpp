#include <types/bot_name.hpp>

#include "common.hpp"

namespace tg {

BotName Parse(const Value& value, To<BotName>) {
    BotName obj{};
    obj.name = ParseComplex<String>(value["name"]);
    return obj;
}

}  // namespace tg
