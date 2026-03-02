#pragma once

#include <types/common.hpp>
#include <types/video.hpp>

namespace tg {

struct PaidMediaVideo {
    String type;
    Video video;
};

PaidMediaVideo Parse(const Value& value, To<PaidMediaVideo>);

}  // namespace tg
