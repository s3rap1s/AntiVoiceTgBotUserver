#include <types/labeled_price.hpp>

#include "common.hpp"

namespace tg {

LabeledPrice Parse(const Value& value, To<LabeledPrice>) {
    LabeledPrice obj{};
    obj.label = ParseComplex<String>(value["label"]);
    obj.amount = ParseComplex<Integer>(value["amount"]);
    return obj;
}

}  // namespace tg
