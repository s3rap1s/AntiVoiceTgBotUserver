#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/paid_media.hpp>

namespace tg {

struct PaidMediaInfo {
    Integer star_count;
    Array<PaidMedia> paid_media;
};

PaidMediaInfo Parse(const Value& value, To<PaidMediaInfo>);

void Serialize(const PaidMediaInfo& obj, ValueBuilder& builder);

}  // namespace tg
