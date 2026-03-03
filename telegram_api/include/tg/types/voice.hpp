#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct Voice {
    String file_id;
    String file_unique_id;
    Integer duration;
    Optional<String> mime_type;
    Optional<Integer> file_size;
};

Voice Parse(const Value& value, To<Voice>);

void Serialize(const Voice& obj, ValueBuilder& builder);

}  // namespace tg
