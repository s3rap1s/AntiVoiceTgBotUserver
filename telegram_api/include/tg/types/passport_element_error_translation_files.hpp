#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorTranslationFiles {
    String source;
    String type;
    Array<String> file_hashes;
    String message;
};

PassportElementErrorTranslationFiles Parse(const Value& value, To<PassportElementErrorTranslationFiles>);

void Serialize(const PassportElementErrorTranslationFiles& obj, ValueBuilder& builder);

}  // namespace tg
