#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportElementErrorDataField {
    String source;
    String type;
    String field_name;
    String data_hash;
    String message;
};

PassportElementErrorDataField Parse(const Value& value, To<PassportElementErrorDataField>);

void Serialize(const PassportElementErrorDataField& obj, ValueBuilder& builder);

}  // namespace tg
