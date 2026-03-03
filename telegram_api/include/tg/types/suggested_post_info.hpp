#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/suggested_post_price.hpp>

namespace tg {

struct SuggestedPostInfo {
    String state;
    Optional<SuggestedPostPrice> price;
    Integer send_date;
};

SuggestedPostInfo Parse(const Value& value, To<SuggestedPostInfo>);

void Serialize(const SuggestedPostInfo& obj, ValueBuilder& builder);

}  // namespace tg
