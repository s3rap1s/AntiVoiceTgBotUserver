#include <tg/types/background_fill_solid.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BackgroundFillSolid Parse(const Value& value, To<BackgroundFillSolid>) {
    BackgroundFillSolid obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.color = ParseComplex<Integer>(value["color"]);
    return obj;
}

void Serialize(const BackgroundFillSolid& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "color", obj.color);
}

}  // namespace tg
