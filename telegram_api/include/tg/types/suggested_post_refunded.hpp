#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>

namespace tg {

struct SuggestedPostRefunded {
    MessagePtr suggested_post_message;
    String reason;
};

SuggestedPostRefunded Parse(const Value& value, To<SuggestedPostRefunded>);

void Serialize(const SuggestedPostRefunded& obj, ValueBuilder& builder);

}  // namespace tg
