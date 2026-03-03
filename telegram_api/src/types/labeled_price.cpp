#include <tg/types/labeled_price.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

LabeledPrice Parse(const Value& value, To<LabeledPrice>) {
    LabeledPrice obj{};
    obj.label = ParseComplex<String>(value["label"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    return obj;
}

void Serialize(const LabeledPrice& obj, ValueBuilder& builder) {
    internal::Put(builder, "label", obj.label);
    internal::Put(builder, "amount", obj.amount);
}

}  // namespace tg
