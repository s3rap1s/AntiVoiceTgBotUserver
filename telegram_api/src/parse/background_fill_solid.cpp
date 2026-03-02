#include <tg/types/background_fill_solid.hpp>

#include "common.hpp"

namespace tg {

BackgroundFillSolid Parse(const Value& value, To<BackgroundFillSolid>) {
    BackgroundFillSolid obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.color = ParseComplex<Integer>(value["color"]);
    return obj;
}

}  // namespace tg
