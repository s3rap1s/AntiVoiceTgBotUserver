#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorTranslationFile {
    String source;
    String type;
    String file_hash;
    String message;
};

PassportElementErrorTranslationFile Parse(const Value& value, To<PassportElementErrorTranslationFile>);

void Serialize(const PassportElementErrorTranslationFile& obj, ValueBuilder& builder);

}  // namespace tg
