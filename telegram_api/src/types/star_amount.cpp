#include <tg/types/star_amount.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

StarAmount Parse(const Value& value, To<StarAmount>) {
    StarAmount obj{};
    obj.amount = ParseComplex<Integer>(value["amount"]);
    obj.nanostar_amount = ParseComplex<Optional<Integer>>(value["nanostar_amount"]);
    return obj;
}

void Serialize(const StarAmount& obj, ValueBuilder& builder) {
    internal::Put(builder, "amount", obj.amount);
    internal::Put(builder, "nanostar_amount", obj.nanostar_amount);
}

}  // namespace tg
