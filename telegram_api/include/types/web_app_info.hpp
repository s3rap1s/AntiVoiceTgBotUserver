#pragma once

#include "common.hpp"

namespace tg {

struct WebAppInfo {
    String url;
};

WebAppInfo Parse(const Value& value, To<WebAppInfo>);

}  // namespace tg
