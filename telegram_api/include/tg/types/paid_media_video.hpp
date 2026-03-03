#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/video.hpp>

namespace tg {

struct PaidMediaVideo {
    String type;
    Video video;
};

PaidMediaVideo Parse(const Value& value, To<PaidMediaVideo>);

void Serialize(const PaidMediaVideo& obj, ValueBuilder& builder);

}  // namespace tg
