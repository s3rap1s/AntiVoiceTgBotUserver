#pragma once

#include <types/common.hpp>

namespace tg {

struct InputStoryContentPhoto {
    String type;
    String photo;
};

InputStoryContentPhoto Parse(const Value& value, To<InputStoryContentPhoto>);

}  // namespace tg
