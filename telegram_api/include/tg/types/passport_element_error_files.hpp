#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorFiles {
    String source;
    String type;
    Array<String> file_hashes;
    String message;
};

PassportElementErrorFiles Parse(const Value& value, To<PassportElementErrorFiles>);

void Serialize(const PassportElementErrorFiles& obj, ValueBuilder& builder);

}  // namespace tg
