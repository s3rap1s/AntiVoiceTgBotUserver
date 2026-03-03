#include <tg/types/paid_media.hpp>
#include <tg/types/paid_media_photo.hpp>
#include <tg/types/paid_media_preview.hpp>
#include <tg/types/paid_media_video.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PaidMedia Parse(const Value& value, To<PaidMedia>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "preview") return ParseComplex<PaidMediaPreview>(value);
    if (type == "photo") return ParseComplex<PaidMediaPhoto>(value);
    if (type == "video") return ParseComplex<PaidMediaVideo>(value);
    throw std::runtime_error("Unknown PaidMedia type: " + type);
}

void Serialize(const PaidMedia& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
