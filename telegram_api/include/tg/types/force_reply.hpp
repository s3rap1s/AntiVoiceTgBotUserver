#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct ForceReply {
    OptionalTrue force_reply;
    Optional<String> input_field_placeholder;
    Optional<Boolean> selective;
};

ForceReply Parse(const Value& value, To<ForceReply>);

}  // namespace tg
