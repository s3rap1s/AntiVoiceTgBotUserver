#pragma once

#include <types/common.hpp>

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

}  // namespace tg
