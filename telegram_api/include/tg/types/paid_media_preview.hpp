#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct PaidMediaPreview {
    String type;
    Optional<Integer> width;
    Optional<Integer> height;
    Optional<Integer> duration;
};

PaidMediaPreview Parse(const Value& value, To<PaidMediaPreview>);

void Serialize(const PaidMediaPreview& obj, ValueBuilder& builder);

}  // namespace tg
