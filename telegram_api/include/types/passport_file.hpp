#pragma once

#include <types/common.hpp>

namespace tg {

struct PassportFile {
    String file_id;
    String file_unique_id;
    Integer file_size;
    Integer file_date;
};

PassportFile Parse(const Value& value, To<PassportFile>);

}  // namespace tg
