#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Boolean BotApi::AnswerInlineQuery(String inline_query_id, Array<InlineQueryResult> results,
                                  Optional<Integer> cache_time, Optional<Boolean> is_personal,
                                  Optional<String> next_offset, Optional<InlineQueryResultButton> button) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "inline_query_id", inline_query_id);
    internal::Put(builder, "results", results);
    internal::Put(builder, "cache_time", cache_time);
    internal::Put(builder, "is_personal", is_personal);
    internal::Put(builder, "next_offset", next_offset);
    internal::Put(builder, "button", button);

    const auto result = client->CallResult("answerInlineQuery", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

SentWebAppMessage BotApi::AnswerWebAppQuery(String web_app_query_id, InlineQueryResult result) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "web_app_query_id", web_app_query_id);
    internal::Put(builder, "result", result);

    const auto resultJ = client->CallResult("answerWebAppQuery", builder.ExtractValue(), timeouts.common);

    return resultJ.As<SentWebAppMessage>();
}

PreparedInlineMessage BotApi::SavePreparedInlineMessage(Integer user_id, InlineQueryResult result,
                                                        Optional<Boolean> allow_user_chats,
                                                        Optional<Boolean> allow_bot_chats,
                                                        Optional<Boolean> allow_group_chats,
                                                        Optional<Boolean> allow_channel_chats) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "result", result);
    internal::Put(builder, "allow_user_chats", allow_user_chats);
    internal::Put(builder, "allow_bot_chats", allow_bot_chats);
    internal::Put(builder, "allow_group_chats", allow_group_chats);
    internal::Put(builder, "allow_channel_chats", allow_channel_chats);

    const auto resultJ = client->CallResult("savePreparedInlineMessage", builder.ExtractValue(), timeouts.common);

    return resultJ.As<PreparedInlineMessage>();
}

}  // namespace tg
