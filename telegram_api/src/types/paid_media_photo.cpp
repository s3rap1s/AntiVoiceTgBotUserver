#include <tg/types/paid_media_photo.hpp>
#include <tg/types/photo_size.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PaidMediaPhoto Parse(const Value& value, To<PaidMediaPhoto>) {
    PaidMediaPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.photo = ParseComplex<Array<PhotoSize>>(value["photo"]);
    return obj;
}

void Serialize(const PaidMediaPhoto& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "photo", obj.photo);
}

}  // namespace tg
