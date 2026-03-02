#include <types/reaction_count.hpp>
#include <types/reaction_type.hpp>

#include "common.hpp"

namespace tg {

ReactionCount Parse(const Value& value, To<ReactionCount>) {
    ReactionCount obj{};
    obj.type = ParseComplex<ReactionType>(value["type"]);
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    return obj;
}

}  // namespace tg
