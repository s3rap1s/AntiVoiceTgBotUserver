#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>
#include <tg/types/suggested_post_price.hpp>

namespace tg {

struct SuggestedPostApproved {
    MessagePtr suggested_post_message;
    Optional<SuggestedPostPrice> price;
    Integer send_date;
};

SuggestedPostApproved Parse(const Value& value, To<SuggestedPostApproved>);

void Serialize(const SuggestedPostApproved& obj, ValueBuilder& builder);

}  // namespace tg
