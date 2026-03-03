#include <tg/types/background_type_chat_theme.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BackgroundTypeChatTheme Parse(const Value& value, To<BackgroundTypeChatTheme>) {
    BackgroundTypeChatTheme obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.theme_name = ParseComplex<String>(value["theme_name"]);
    return obj;
}

void Serialize(const BackgroundTypeChatTheme& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "theme_name", obj.theme_name);
}

}  // namespace tg
