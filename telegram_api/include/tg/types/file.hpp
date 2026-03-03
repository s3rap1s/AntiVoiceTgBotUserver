#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct File {
    String file_id;
    String file_unique_id;
    Optional<Integer> file_size;
    Optional<String> file_path;
};

File Parse(const Value& value, To<File>);

void Serialize(const File& obj, ValueBuilder& builder);

}  // namespace tg
