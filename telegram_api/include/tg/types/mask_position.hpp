#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct MaskPosition {
    String point;
    Float x_shift;
    Float y_shift;
    Float scale;
};

MaskPosition Parse(const Value& value, To<MaskPosition>);

}  // namespace tg
