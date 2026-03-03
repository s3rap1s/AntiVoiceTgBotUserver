#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct WebAppData {
    String data;
    String button_text;
};

WebAppData Parse(const Value& value, To<WebAppData>);

void Serialize(const WebAppData& obj, ValueBuilder& builder);

}  // namespace tg
