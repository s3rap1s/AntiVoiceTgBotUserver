#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/photo_size.hpp>

namespace tg {

struct VideoNote {
    String file_id;
    String file_unique_id;
    Integer length;
    Integer duration;
    Optional<PhotoSize> thumbnail;
    Optional<Integer> file_size;
};

VideoNote Parse(const Value& value, To<VideoNote>);

void Serialize(const VideoNote& obj, ValueBuilder& builder);

}  // namespace tg
