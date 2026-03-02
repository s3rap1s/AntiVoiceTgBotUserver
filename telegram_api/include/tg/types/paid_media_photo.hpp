#pragma once

#include <tg/types/common.hpp>
#include <tg/types/photo_size.hpp>

namespace tg {

struct PaidMediaPhoto {
    String type;
    Array<PhotoSize> photo;
};

PaidMediaPhoto Parse(const Value& value, To<PaidMediaPhoto>);

}  // namespace tg
