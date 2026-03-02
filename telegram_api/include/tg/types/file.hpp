#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct File {
    String file_id;
    String file_unique_id;
    Optional<Integer> file_size;
    Optional<String> file_path;
};

File Parse(const Value& value, To<File>);

}  // namespace tg
