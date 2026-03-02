#include <tg/types/input_paid_media.hpp>
#include <tg/types/input_paid_media_photo.hpp>
#include <tg/types/input_paid_media_video.hpp>

#include "common.hpp"

namespace tg {

InputPaidMedia Parse(const Value& value, To<InputPaidMedia>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "photo") return ParseComplex<InputPaidMediaPhoto>(value);
    if (type == "video") return ParseComplex<InputPaidMediaVideo>(value);
    throw std::runtime_error("Unknown InputPaidMedia type: " + type);
}

}  // namespace tg
