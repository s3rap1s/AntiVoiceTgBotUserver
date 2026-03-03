#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorFile {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorFile Parse(const Value& value, To<PassportElementErrorFile>);

void Serialize(const PassportElementErrorFile& obj, ValueBuilder& builder);

}  // namespace tg
