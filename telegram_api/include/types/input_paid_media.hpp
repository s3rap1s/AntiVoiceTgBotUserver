#pragma once

#include "common.hpp"
#include "input_paid_media_photo.hpp"
#include "input_paid_media_video.hpp"

namespace tg {

using InputPaidMedia = OneOf<InputPaidMediaPhoto, InputPaidMediaVideo>;

InputPaidMedia Parse(const Value& value, To<InputPaidMedia>);

}  // namespace tg
