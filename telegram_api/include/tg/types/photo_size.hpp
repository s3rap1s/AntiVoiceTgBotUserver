#pragma once

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

}  // namespace tg
