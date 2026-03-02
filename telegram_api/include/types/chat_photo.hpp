#pragma once

#include <types/common.hpp>

namespace tg {

struct ChatPhoto {
    String small_file_id;
    String small_file_unique_id;
    String big_file_id;
    String big_file_unique_id;
};

ChatPhoto Parse(const Value& value, To<ChatPhoto>);

}  // namespace tg
