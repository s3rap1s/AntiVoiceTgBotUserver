#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorSelfie {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorSelfie Parse(const Value& value, To<PassportElementErrorSelfie>);

void Serialize(const PassportElementErrorSelfie& obj, ValueBuilder& builder);

}  // namespace tg
