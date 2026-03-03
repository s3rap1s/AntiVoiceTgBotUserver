#include <tg/types/gift.hpp>
#include <tg/types/gifts.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Gifts Parse(const Value& value, To<Gifts>) {
    Gifts obj{};
    obj.gifts = ParseComplex<Array<Gift>>(value["gifts"]);
    return obj;
}

void Serialize(const Gifts& obj, ValueBuilder& builder) { internal::Put(builder, "gifts", obj.gifts); }

}  // namespace tg
