#include <tg/types/bot_description.hpp>

#include "common.hpp"

namespace tg {

BotDescription Parse(const Value& value, To<BotDescription>) {
    BotDescription obj{};
    obj.description = ParseComplex<String>(value["description"]);
    return obj;
}

}  // namespace tg
