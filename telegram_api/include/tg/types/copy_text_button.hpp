#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct CopyTextButton {
    String text;
};

CopyTextButton Parse(const Value& value, To<CopyTextButton>);

void Serialize(const CopyTextButton& obj, ValueBuilder& builder);

}  // namespace tg
