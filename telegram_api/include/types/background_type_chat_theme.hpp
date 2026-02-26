#pragma once

#include "common.hpp"

namespace tg {

struct BackgroundTypeChatTheme {
    String type;
    String theme_name;
};

BackgroundTypeChatTheme Parse(const Value& value, To<BackgroundTypeChatTheme>);

}  // namespace tg
