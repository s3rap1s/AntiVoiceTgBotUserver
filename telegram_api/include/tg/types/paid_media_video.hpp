#pragma once

#include <tg/types/common.hpp>
#include <tg/types/video.hpp>

namespace tg {

struct PaidMediaVideo {
    String type;
    Video video;
};

PaidMediaVideo Parse(const Value& value, To<PaidMediaVideo>);

}  // namespace tg
