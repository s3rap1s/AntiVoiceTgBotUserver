#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_ptr.hpp>

namespace tg {

struct SuggestedPostDeclined {
    MessagePtr suggested_post_message;
    Optional<String> comment;
};

SuggestedPostDeclined Parse(const Value& value, To<SuggestedPostDeclined>);

void Serialize(const SuggestedPostDeclined& obj, ValueBuilder& builder);

}  // namespace tg
