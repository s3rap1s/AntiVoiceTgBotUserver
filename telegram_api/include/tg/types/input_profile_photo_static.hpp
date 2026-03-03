#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct InputProfilePhotoStatic {
    String type;
    String photo;
};

InputProfilePhotoStatic Parse(const Value& value, To<InputProfilePhotoStatic>);

void Serialize(const InputProfilePhotoStatic& obj, ValueBuilder& builder);

}  // namespace tg
