#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Boolean BotApi::AnswerCallbackQuery(String callback_query_id, Optional<String> text, Optional<Boolean> show_alert,
                                    Optional<String> url, Optional<Integer> cache_time) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "callback_query_id", callback_query_id);
    internal::Put(builder, "text", text);
    internal::Put(builder, "show_alert", show_alert);
    internal::Put(builder, "url", url);
    internal::Put(builder, "cache_time", cache_time);

    const auto result = client->CallResult("answerCallbackQuery", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
