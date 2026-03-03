#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct InputStoryContentPhoto {
    String type;
    String photo;
};

InputStoryContentPhoto Parse(const Value& value, To<InputStoryContentPhoto>);

void Serialize(const InputStoryContentPhoto& obj, ValueBuilder& builder);

}  // namespace tg
