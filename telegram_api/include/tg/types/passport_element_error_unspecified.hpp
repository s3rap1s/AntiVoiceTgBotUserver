#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorUnspecified {
    String source;
    String type;
    String element_hash;
    String message;
};

PassportElementErrorUnspecified Parse(const Value& value, To<PassportElementErrorUnspecified>);

void Serialize(const PassportElementErrorUnspecified& obj, ValueBuilder& builder);

}  // namespace tg
