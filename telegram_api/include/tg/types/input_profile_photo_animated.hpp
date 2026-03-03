#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct InputProfilePhotoAnimated {
    String type;
    String animation;
    Optional<Float> main_frame_timestamp;
};

InputProfilePhotoAnimated Parse(const Value& value, To<InputProfilePhotoAnimated>);

void Serialize(const InputProfilePhotoAnimated& obj, ValueBuilder& builder);

}  // namespace tg
