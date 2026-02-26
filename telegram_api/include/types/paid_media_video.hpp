#pragma once

#include "common.hpp"
#include "video.hpp"

namespace tg {

struct PaidMediaVideo {
    String type;
    Array<Video> photo;
};

PaidMediaVideo Parse(const Value& value, To<PaidMediaVideo>);

}  // namespace tg
