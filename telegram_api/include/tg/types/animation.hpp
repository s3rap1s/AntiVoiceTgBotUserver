#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/photo_size.hpp>

namespace tg {

struct Animation {
    String file_id;
    String file_unique_id;
    Integer width;
    Integer height;
    Integer duration;
    Optional<PhotoSize> thumbnail;
    Optional<String> file_name;
    Optional<String> mime_type;
    Optional<Integer> file_size;
};

Animation Parse(const Value& value, To<Animation>);

void Serialize(const Animation& obj, ValueBuilder& builder);

}  // namespace tg
