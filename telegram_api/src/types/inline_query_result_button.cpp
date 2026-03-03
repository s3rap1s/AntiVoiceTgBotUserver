#include <tg/types/inline_query_result_button.hpp>
#include <tg/types/web_app_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultButton Parse(const Value& value, To<InlineQueryResultButton>) {
    InlineQueryResultButton obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.web_app = ParseComplex<Optional<WebAppInfo>>(value["web_app"]);
    obj.start_parameter = ParseComplex<Optional<String>>(value["start_parameter"]);
    return obj;
}

void Serialize(const InlineQueryResultButton& obj, ValueBuilder& builder) {
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "web_app", obj.web_app);
    internal::Put(builder, "start_parameter", obj.start_parameter);
}

}  // namespace tg
