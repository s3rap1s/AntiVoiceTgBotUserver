#pragma once

#include "paid_media_photo.hpp"
#include "paid_media_preview.hpp"
#include "paid_media_video.hpp"

namespace tg {

using PaidMedia = OneOf<PaidMediaPreview, PaidMediaPhoto, PaidMediaVideo>;

PaidMedia Parse(const Value& value, To<PaidMedia>);

}  // namespace tg
