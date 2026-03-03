#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct InputPaidMediaPhoto {
    String type;
    String media;
};

InputPaidMediaPhoto Parse(const Value& value, To<InputPaidMediaPhoto>);

void Serialize(const InputPaidMediaPhoto& obj, ValueBuilder& builder);

}  // namespace tg
