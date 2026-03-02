#pragma once

#include <types/common.hpp>
#include <types/photo_size.hpp>

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

}  // namespace tg
