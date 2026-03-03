#include <tg/types/reaction_type_paid.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ReactionTypePaid Parse(const Value& value, To<ReactionTypePaid>) {
    ReactionTypePaid obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

void Serialize(const ReactionTypePaid& obj, ValueBuilder& builder) { internal::Put(builder, "type", obj.type); }

}  // namespace tg
