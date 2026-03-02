#include <types/inline_query_result_button.hpp>
#include <types/web_app_info.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultButton Parse(const Value& value, To<InlineQueryResultButton>) {
    InlineQueryResultButton obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.web_app = ParseComplex<Optional<WebAppInfo>>(value["web_app"]);
    obj.start_parameter =
        ParseComplex<Optional<String>>(value["start_parameter"]);
    return obj;
}

}  // namespace tg
