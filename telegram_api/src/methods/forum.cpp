#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Array<Sticker> BotApi::GetForumTopicIconStickers() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("getForumTopicIconStickers", builder.ExtractValue(), timeouts.common);

    Array<Sticker> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<Sticker>());
    }
    return out;
}

ForumTopic BotApi::CreateForumTopic(OneOf<Integer, String> chat_id, String name, Optional<Integer> icon_color,
                                    Optional<String> icon_custom_emoji_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "name", name);
    internal::Put(builder, "icon_color", icon_color);
    internal::Put(builder, "icon_custom_emoji_id", icon_custom_emoji_id);

    const auto result = client->CallResult("createForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<ForumTopic>();
}

Boolean BotApi::EditForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id, Optional<String> name,
                               Optional<String> icon_custom_emoji_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "name", name);
    internal::Put(builder, "icon_custom_emoji_id", icon_custom_emoji_id);

    const auto result = client->CallResult("editForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::CloseForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_thread_id", message_thread_id);

    const auto result = client->CallResult("closeForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::ReopenForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_thread_id", message_thread_id);

    const auto result = client->CallResult("reopenForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_thread_id", message_thread_id);

    const auto result = client->CallResult("deleteForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UnpinAllForumTopicMessages(OneOf<Integer, String> chat_id, Integer message_thread_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_thread_id", message_thread_id);

    const auto result = client->CallResult("unpinAllForumTopicMessages", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::EditGeneralForumTopic(OneOf<Integer, String> chat_id, String name) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "name", name);

    const auto result = client->CallResult("editGeneralForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::CloseGeneralForumTopic(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("closeGeneralForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::ReopenGeneralForumTopic(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("reopenGeneralForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::HideGeneralForumTopic(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("hideGeneralForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UnhideGeneralForumTopic(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("unhideGeneralForumTopic", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UnpinAllGeneralForumTopicMessages(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result =
        client->CallResult("unpinAllGeneralForumTopicMessages", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
