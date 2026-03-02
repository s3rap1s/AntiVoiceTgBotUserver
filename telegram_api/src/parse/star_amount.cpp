#include <types/star_amount.hpp>

#include "common.hpp"

namespace tg {

StarAmount Parse(const Value& value, To<StarAmount>) {
    StarAmount obj{};
    obj.amount = ParseComplex<Integer>(value["amount"]);
    obj.nanostar_amount =
        ParseComplex<Optional<Integer>>(value["nanostar_amount"]);
    return obj;
}

}  // namespace tg
