#include <types/paid_media_photo.hpp>
#include <types/photo_size.hpp>

#include "common.hpp"

namespace tg {

PaidMediaPhoto Parse(const Value& value, To<PaidMediaPhoto>) {
    PaidMediaPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.photo = ParseComplex<Array<PhotoSize>>(value["photo"]);
    return obj;
}

}  // namespace tg
