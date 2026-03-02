#pragma once

#include <tg/types/common.hpp>
#include <tg/types/web_app_info.hpp>

namespace tg {

struct InlineQueryResultButton {
    String text;
    Optional<WebAppInfo> web_app;
    Optional<String> start_parameter;
};

InlineQueryResultButton Parse(const Value& value, To<InlineQueryResultButton>);

}  // namespace tg
