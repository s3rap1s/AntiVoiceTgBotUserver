#pragma once

#include "common.hpp"
#include "photo_size.hpp"
#include "video_quality.hpp"

namespace tg {

struct Video {
    String file_id;
    String file_unique_id;
    Integer width;
    Integer height;
    Integer duration;
    Optional<PhotoSize> thumbnail;
    Optional<Array<PhotoSize>> cover;
    Optional<Integer> start_timestamp;
    Optional<Array<VideoQuality>> qualities;
    Optional<String> file_name;
    Optional<String> mime_type;
    Optional<Integer> file_size;
};

Video Parse(const Value& value, To<Video>);

}  // namespace tg
