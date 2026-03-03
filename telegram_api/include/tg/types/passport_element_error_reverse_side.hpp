#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorReverseSide {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorReverseSide Parse(const Value& value, To<PassportElementErrorReverseSide>);

void Serialize(const PassportElementErrorReverseSide& obj, ValueBuilder& builder);

}  // namespace tg
