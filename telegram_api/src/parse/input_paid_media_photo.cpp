#include <tg/types/input_paid_media_photo.hpp>

#include "common.hpp"

namespace tg {

InputPaidMediaPhoto Parse(const Value& value, To<InputPaidMediaPhoto>) {
    InputPaidMediaPhoto obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.media = ParseComplex<String>(value["media"]);
    return obj;
}

}  // namespace tg
