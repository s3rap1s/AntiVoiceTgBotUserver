#include <tg/types/gift.hpp>
#include <tg/types/gifts.hpp>

#include "common.hpp"

namespace tg {

Gifts Parse(const Value& value, To<Gifts>) {
    Gifts obj{};
    obj.gifts = ParseComplex<Array<Gift>>(value["gifts"]);
    return obj;
}

}  // namespace tg
