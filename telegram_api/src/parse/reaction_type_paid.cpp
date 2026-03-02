#include <tg/types/reaction_type_paid.hpp>

#include "common.hpp"

namespace tg {

ReactionTypePaid Parse(const Value& value, To<ReactionTypePaid>) {
    ReactionTypePaid obj{};
    obj.type = ParseComplex<String>(value["type"]);
    return obj;
}

}  // namespace tg
