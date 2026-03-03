#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct WebAppInfo {
    String url;
};

WebAppInfo Parse(const Value& value, To<WebAppInfo>);

void Serialize(const WebAppInfo& obj, ValueBuilder& builder);

}  // namespace tg
