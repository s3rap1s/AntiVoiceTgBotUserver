#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>
#include <tg/types/suggested_post_price.hpp>

namespace tg {

struct SuggestedPostApprovalFailed {
    MessagePtr suggested_post_message;
    SuggestedPostPrice price;
};

SuggestedPostApprovalFailed Parse(const Value& value, To<SuggestedPostApprovalFailed>);

void Serialize(const SuggestedPostApprovalFailed& obj, ValueBuilder& builder);

}  // namespace tg
