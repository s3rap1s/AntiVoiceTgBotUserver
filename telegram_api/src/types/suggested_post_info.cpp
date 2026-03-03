#include <tg/types/suggested_post_info.hpp>
#include <tg/types/suggested_post_price.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuggestedPostInfo Parse(const Value& value, To<SuggestedPostInfo>) {
    SuggestedPostInfo obj{};
    obj.state = ParseComplex<String>(value["state"]);
    obj.price = ParseComplex<Optional<SuggestedPostPrice>>(value["price"]);
    obj.send_date = ParseComplex<Integer>(value["send_date"]);
    return obj;
}

void Serialize(const SuggestedPostInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "state", obj.state);
    internal::Put(builder, "price", obj.price);
    internal::Put(builder, "send_date", obj.send_date);
}

}  // namespace tg
