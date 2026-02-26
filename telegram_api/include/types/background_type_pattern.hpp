#pragma once

#include "background_fill.hpp"
#include "common.hpp"
#include "document.hpp"

namespace tg {

struct BackgroundTypePattern {
    String type;
    Document document;
    BackgroundFill fill;
    Integer intensity;
    OptionalTrue is_inverted;
    OptionalTrue is_moving;
};

BackgroundTypePattern Parse(const Value& value, To<BackgroundTypePattern>);

}  // namespace tg
