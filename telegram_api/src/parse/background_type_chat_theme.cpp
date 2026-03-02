#include <tg/types/background_type_chat_theme.hpp>

#include "common.hpp"

namespace tg {

BackgroundTypeChatTheme Parse(const Value& value, To<BackgroundTypeChatTheme>) {
    BackgroundTypeChatTheme obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.theme_name = ParseComplex<String>(value["theme_name"]);
    return obj;
}

}  // namespace tg
