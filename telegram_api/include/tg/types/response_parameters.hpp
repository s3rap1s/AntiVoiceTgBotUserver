#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct ResponseParameters {
    Optional<Integer> migrate_to_chat_id;
    Optional<Integer> retry_after;
};

ResponseParameters Parse(const Value& value, To<ResponseParameters>);

}  // namespace tg
