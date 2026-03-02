#include <types/paid_media_preview.hpp>

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

}  // namespace tg
