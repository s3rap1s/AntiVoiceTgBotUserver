#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct VideoQuality {
    String file_id;
    String file_unique_id;
    Integer width;
    Integer height;
    String codec;
    Optional<Integer> file_size;
};

VideoQuality Parse(const Value& value, To<VideoQuality>);

void Serialize(const VideoQuality& obj, ValueBuilder& builder);

}  // namespace tg
