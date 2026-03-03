#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorFrontSide {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorFrontSide Parse(const Value& value, To<PassportElementErrorFrontSide>);

void Serialize(const PassportElementErrorFrontSide& obj, ValueBuilder& builder);

}  // namespace tg
