#pragma once

#include <types/common.hpp>

namespace tg {

struct InputPaidMediaPhoto {
    String type;
    String media;
};

InputPaidMediaPhoto Parse(const Value& value, To<InputPaidMediaPhoto>);

}  // namespace tg
