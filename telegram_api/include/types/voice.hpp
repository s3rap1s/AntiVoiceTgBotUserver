#pragma once

#include <types/common.hpp>

namespace tg {

struct Voice {
    String file_id;
    String file_unique_id;
    Integer duration;
    Optional<String> mime_type;
    Optional<Integer> file_size;
};

Voice Parse(const Value& value, To<Voice>);

}  // namespace tg
