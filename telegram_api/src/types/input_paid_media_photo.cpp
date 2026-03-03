#include <tg/types/input_paid_media_photo.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputPaidMediaPhoto Parse(const Value& value, To<InputPaidMediaPhoto>) {
    InputPaidMediaPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    return obj;
}

void Serialize(const InputPaidMediaPhoto& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "media", obj.media);
}

}  // namespace tg
