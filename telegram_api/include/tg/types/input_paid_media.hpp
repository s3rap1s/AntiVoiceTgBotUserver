#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/input_paid_media_photo.hpp>
#include <tg/types/input_paid_media_video.hpp>

namespace tg {

using InputPaidMedia = OneOf<InputPaidMediaPhoto, InputPaidMediaVideo>;

InputPaidMedia Parse(const Value& value, To<InputPaidMedia>);

void Serialize(const InputPaidMedia& obj, ValueBuilder& builder);

}  // namespace tg
