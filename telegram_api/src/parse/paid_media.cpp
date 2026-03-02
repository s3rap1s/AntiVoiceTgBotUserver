#include <types/paid_media.hpp>
#include <types/paid_media_photo.hpp>
#include <types/paid_media_preview.hpp>
#include <types/paid_media_video.hpp>

#include "common.hpp"

namespace tg {

PaidMedia Parse(const Value& value, To<PaidMedia>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "preview") return ParseComplex<PaidMediaPreview>(value);
    if (type == "photo") return ParseComplex<PaidMediaPhoto>(value);
    if (type == "video") return ParseComplex<PaidMediaVideo>(value);
    throw std::runtime_error("Unknown PaidMedia type: " + type);
}

}  // namespace tg
