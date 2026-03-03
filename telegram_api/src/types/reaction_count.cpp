#include <tg/types/reaction_count.hpp>
#include <tg/types/reaction_type.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReactionCount Parse(const Value& value, To<ReactionCount>) {
    ReactionCount obj{};
    obj.type = ParseComplex<ReactionType>(value["type"]);
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    return obj;
}

void Serialize(const ReactionCount& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "total_count", obj.total_count);
}

}  // namespace tg
