#pragma once

#include <types/common.hpp>
#include <types/suggested_post_price.hpp>

namespace tg {

struct SuggestedPostInfo {
    String state;
    Optional<SuggestedPostPrice> price;
    Integer send_date;
};

SuggestedPostInfo Parse(const Value& value, To<SuggestedPostInfo>);

}  // namespace tg
