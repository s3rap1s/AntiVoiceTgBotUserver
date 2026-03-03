#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/background_fill.hpp>
#include <tg/types/common.hpp>
#include <tg/types/document.hpp>

namespace tg {

struct BackgroundTypePattern {
    String type;
    Document document;
    BackgroundFill fill;
    Integer intensity;
    OptionalTrue is_inverted;
    OptionalTrue is_moving;
};

BackgroundTypePattern Parse(const Value& value, To<BackgroundTypePattern>);

void Serialize(const BackgroundTypePattern& obj, ValueBuilder& builder);

}  // namespace tg
