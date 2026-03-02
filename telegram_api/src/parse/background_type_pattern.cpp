#include <types/background_fill.hpp>
#include <types/background_type_pattern.hpp>
#include <types/document.hpp>

#include "common.hpp"

namespace tg {

BackgroundTypePattern Parse(const Value& value, To<BackgroundTypePattern>) {
    BackgroundTypePattern obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.document = ParseComplex<Document>(value["document"]);
    obj.fill = ParseComplex<BackgroundFill>(value["fill"]);
    obj.intensity = ParseComplex<Integer>(value["intensity"]);
    obj.is_inverted = ParseComplex<OptionalTrue>(value["is_inverted"]);
    obj.is_moving = ParseComplex<OptionalTrue>(value["is_moving"]);
    return obj;
}

}  // namespace tg
