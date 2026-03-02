#include <types/suggested_post_info.hpp>
#include <types/suggested_post_price.hpp>

#include "common.hpp"

namespace tg {

SuggestedPostInfo Parse(const Value& value, To<SuggestedPostInfo>) {
    SuggestedPostInfo obj{};
    obj.state = ParseComplex<String>(value["state"]);
    obj.price = ParseComplex<Optional<SuggestedPostPrice>>(value["price"]);
    obj.send_date = ParseComplex<Integer>(value["send_date"]);
    return obj;
}

}  // namespace tg
