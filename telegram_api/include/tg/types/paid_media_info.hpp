#pragma once

#include <tg/types/common.hpp>
#include <tg/types/paid_media.hpp>

namespace tg {

struct PaidMediaInfo {
    Integer star_count;
    Array<PaidMedia> paid_media;
};

PaidMediaInfo Parse(const Value& value, To<PaidMediaInfo>);

}  // namespace tg
