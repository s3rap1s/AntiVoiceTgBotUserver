#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PassportFile {
    String file_id;
    String file_unique_id;
    Integer file_size;
    Integer file_date;
};

PassportFile Parse(const Value& value, To<PassportFile>);

void Serialize(const PassportFile& obj, ValueBuilder& builder);

}  // namespace tg
