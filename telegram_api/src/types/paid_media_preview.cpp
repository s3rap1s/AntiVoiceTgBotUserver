#include <tg/types/paid_media_preview.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PaidMediaPreview Parse(const Value& value, To<PaidMediaPreview>) {
    PaidMediaPreview obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.width = ParseComplex<Optional<Integer>>(value["width"]);
    obj.height = ParseComplex<Optional<Integer>>(value["height"]);
    obj.duration = ParseComplex<Optional<Integer>>(value["duration"]);
    return obj;
}

void Serialize(const PaidMediaPreview& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "width", obj.width);
    internal::Put(builder, "height", obj.height);
    internal::Put(builder, "duration", obj.duration);
}

}  // namespace tg
