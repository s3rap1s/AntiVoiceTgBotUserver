#include <tg/types/background_fill.hpp>
#include <tg/types/background_type_fill.hpp>

#include "common.hpp"

namespace tg {

BackgroundTypeFill Parse(const Value& value, To<BackgroundTypeFill>) {
    BackgroundTypeFill obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.fill = ParseComplex<BackgroundFill>(value["fill"]);
    obj.dark_theme_dimming = ParseComplex<Integer>(value["dark_theme_dimming"]);
    return obj;
}

}  // namespace tg
