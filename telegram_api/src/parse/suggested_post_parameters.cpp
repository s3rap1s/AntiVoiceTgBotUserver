#include <tg/types/suggested_post_parameters.hpp>
#include <tg/types/suggested_post_price.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostParameters Parse(const Value& value, To<SuggestedPostParameters>) {
    SuggestedPostParameters obj{};
    obj.price = ParseComplex<Optional<SuggestedPostPrice>>(value["price"]);
    obj.send_date = ParseComplex<Optional<Integer>>(value["send_date"]);
    return obj;
}

}  // namespace tg
