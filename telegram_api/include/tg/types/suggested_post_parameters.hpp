#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/suggested_post_price.hpp>

namespace tg {

struct SuggestedPostParameters {
    Optional<SuggestedPostPrice> price;
    Optional<Integer> send_date;
};

SuggestedPostParameters Parse(const Value& value, To<SuggestedPostParameters>);

void Serialize(const SuggestedPostParameters& obj, ValueBuilder& builder);

}  // namespace tg
