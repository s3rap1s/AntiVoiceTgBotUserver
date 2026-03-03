#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PhotoSize {
    String file_id;
    String file_unique_id;
    Integer width;
    Integer height;
    Optional<Integer> file_size;
};

PhotoSize Parse(const Value& value, To<PhotoSize>);

void Serialize(const PhotoSize& obj, ValueBuilder& builder);

}  // namespace tg
