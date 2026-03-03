#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Message BotApi::SendGame(Integer chat_id, String game_short_name, Optional<String> business_connection_id,
                         Optional<Integer> message_thread_id, Optional<Boolean> disable_notification,
                         Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
                         Optional<String> message_effect_id, Optional<ReplyParameters> reply_parameters,
                         Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "game_short_name", game_short_name);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendGame", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

OneOf<Message, Boolean> BotApi::SetGameScore(Integer user_id, Integer score, Optional<Boolean> force,
                                             Optional<Boolean> disable_edit_message, Optional<Integer> chat_id,
                                             Optional<Integer> message_id, Optional<String> inline_message_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "score", score);
    internal::Put(builder, "force", force);
    internal::Put(builder, "disable_edit_message", disable_edit_message);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);

    const auto result = client->CallResult("setGameScore", builder.ExtractValue(), timeouts.common);

    if (result.IsBool()) {
        return result.As<Boolean>();
    }
    return result.As<Message>();
}

Array<GameHighScore> BotApi::GetGameHighScores(Integer user_id, Optional<Integer> chat_id, Optional<Integer> message_id,
                                               Optional<String> inline_message_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);

    const auto result = client->CallResult("getGameHighScores", builder.ExtractValue(), timeouts.common);

    Array<GameHighScore> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<GameHighScore>());
    }
    return out;
}

}  // namespace tg
