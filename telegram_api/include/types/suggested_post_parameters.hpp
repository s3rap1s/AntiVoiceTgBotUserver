#pragma once

#include "common.hpp"
#include "suggested_post_price.hpp"

namespace tg {

struct SuggestedPostParameters {
    Optional<SuggestedPostPrice> price;
    Optional<Integer> send_date;
};

SuggestedPostParameters Parse(const Value& value, To<SuggestedPostParameters>);

}  // namespace tg
