#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

User BotApi::GetMe() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("getMe", builder.ExtractValue(), timeouts.common);

    return result.As<User>();
}

Boolean BotApi::LogOut() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("logOut", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::Close() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("close", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

BusinessConnection BotApi::GetBusinessConnection(String business_connection_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);

    const auto result = client->CallResult("getBusinessConnection", builder.ExtractValue(), timeouts.common);

    return result.As<BusinessConnection>();
}

Boolean BotApi::SetMyCommands(Array<BotCommand> commands, Optional<BotCommandScope> scope,
                              Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "commands", commands);
    internal::Put(builder, "scope", scope);
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("setMyCommands", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteMyCommands(Optional<BotCommandScope> scope, Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "scope", scope);
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("deleteMyCommands", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Array<BotCommand> BotApi::GetMyCommands(Optional<BotCommandScope> scope, Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "scope", scope);
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("getMyCommands", builder.ExtractValue(), timeouts.common);

    Array<BotCommand> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<BotCommand>());
    }
    return out;
}

Boolean BotApi::SetMyName(Optional<String> name, Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "name", name);
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("setMyName", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

BotName BotApi::GetMyName(Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("getMyName", builder.ExtractValue(), timeouts.common);

    return result.As<BotName>();
}

Boolean BotApi::SetMyDescription(Optional<String> description, Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "description", description);
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("setMyDescription", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

BotDescription BotApi::GetMyDescription(Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("getMyDescription", builder.ExtractValue(), timeouts.common);

    return result.As<BotDescription>();
}

Boolean BotApi::SetMyShortDescription(Optional<String> short_description, Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "short_description", short_description);
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("setMyShortDescription", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

BotShortDescription BotApi::GetMyShortDescription(Optional<String> language_code) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "language_code", language_code);

    const auto result = client->CallResult("getMyShortDescription", builder.ExtractValue(), timeouts.common);

    return result.As<BotShortDescription>();
}

Boolean BotApi::SetMyProfilePhoto(InputProfilePhoto photo) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "photo", photo);

    const auto result = client->CallResult("setMyProfilePhoto", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::RemoveMyProfilePhoto() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("removeMyProfilePhoto", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetChatMenuButton(Optional<Integer> chat_id, Optional<MenuButton> menu_button) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "menu_button", menu_button);

    const auto result = client->CallResult("setChatMenuButton", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

MenuButton BotApi::GetChatMenuButton(Optional<Integer> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("getChatMenuButton", builder.ExtractValue(), timeouts.common);

    return result.As<MenuButton>();
}

}  // namespace tg
