#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ResponseParameters {
    Optional<Integer> migrate_to_chat_id;
    Optional<Integer> retry_after;
};

ResponseParameters Parse(const Value& value, To<ResponseParameters>);

void Serialize(const ResponseParameters& obj, ValueBuilder& builder);

}  // namespace tg
