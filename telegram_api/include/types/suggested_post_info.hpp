#pragma once

#include "common.hpp"
#include "suggested_post_price.hpp"

namespace tg {

struct SuggestedPostInfo {
    String state;
    Optional<SuggestedPostPrice> price;
    Integer send_date;
};

SuggestedPostInfo Parse(const Value& value, To<SuggestedPostInfo>);

}  // namespace tg
