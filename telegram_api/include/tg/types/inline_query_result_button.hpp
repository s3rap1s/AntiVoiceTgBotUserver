#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/web_app_info.hpp>

namespace tg {

struct InlineQueryResultButton {
    String text;
    Optional<WebAppInfo> web_app;
    Optional<String> start_parameter;
};

InlineQueryResultButton Parse(const Value& value, To<InlineQueryResultButton>);

void Serialize(const InlineQueryResultButton& obj, ValueBuilder& builder);

}  // namespace tg
