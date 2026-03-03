#include <tg/types/background_fill.hpp>
#include <tg/types/background_type_pattern.hpp>
#include <tg/types/document.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const BackgroundTypePattern& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "document", obj.document);
    internal::Put(builder, "fill", obj.fill);
    internal::Put(builder, "intensity", obj.intensity);
    internal::Put(builder, "is_inverted", obj.is_inverted);
    internal::Put(builder, "is_moving", obj.is_moving);
}

}  // namespace tg
