#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/photo_size.hpp>

namespace tg {

struct PaidMediaPhoto {
    String type;
    Array<PhotoSize> photo;
};

PaidMediaPhoto Parse(const Value& value, To<PaidMediaPhoto>);

void Serialize(const PaidMediaPhoto& obj, ValueBuilder& builder);

}  // namespace tg
