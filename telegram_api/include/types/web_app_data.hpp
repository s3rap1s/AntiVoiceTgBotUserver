#pragma once

#include "common.hpp"

namespace tg {

struct WebAppData {
    String data;
    String button_text;
};

WebAppData Parse(const Value& value, To<WebAppData>);

}  // namespace tg
