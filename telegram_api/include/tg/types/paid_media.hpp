#pragma once

#include <userver/formats/json/value_builder.hpp>

#include "paid_media_photo.hpp"
#include "paid_media_preview.hpp"
#include "paid_media_video.hpp"

namespace tg {

using ValueBuilder = userver::formats::json::ValueBuilder;

using PaidMedia = OneOf<PaidMediaPreview, PaidMediaPhoto, PaidMediaVideo>;

PaidMedia Parse(const Value& value, To<PaidMedia>);

void Serialize(const PaidMedia& obj, ValueBuilder& builder);

}  // namespace tg
