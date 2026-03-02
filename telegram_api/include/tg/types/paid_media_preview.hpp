#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PaidMediaPreview {
    String type;
    Optional<Integer> width;
    Optional<Integer> height;
    Optional<Integer> duration;
};

PaidMediaPreview Parse(const Value& value, To<PaidMediaPreview>);

}  // namespace tg
