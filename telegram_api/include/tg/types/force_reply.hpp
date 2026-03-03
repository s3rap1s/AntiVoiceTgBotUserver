#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ForceReply {
    OptionalTrue force_reply;
    Optional<String> input_field_placeholder;
    Optional<Boolean> selective;
};

ForceReply Parse(const Value& value, To<ForceReply>);

void Serialize(const ForceReply& obj, ValueBuilder& builder);

}  // namespace tg
