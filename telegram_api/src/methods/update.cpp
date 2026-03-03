#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Array<Update> BotApi::GetUpdates(Optional<Integer> offset, Optional<Integer> limit, Optional<Integer> timeout,
                                 Optional<Array<String>> allowed_updates) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "offset", offset);
    internal::Put(builder, "limit", limit);
    internal::Put(builder, "timeout", timeout);
    internal::Put(builder, "allowed_updates", allowed_updates);

    const auto http_timeout =
        timeout ? std::chrono::duration<Integer>(*timeout) + timeouts.long_poll_add : timeouts.long_poll_add;
    const auto result = client->CallResult("getUpdates", builder.ExtractValue(), http_timeout);

    Array<Update> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<Update>());
    }
    return out;
}

Boolean BotApi::SetWebhook(String url, Optional<InputFile> certificate, Optional<String> ip_address,
                           Optional<Integer> max_connections, Optional<Array<String>> allowed_updates,
                           Optional<Boolean> drop_pending_updates, Optional<String> secret_token) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "url", url);
    internal::Put(builder, "certificate", certificate);
    internal::Put(builder, "ip_address", ip_address);
    internal::Put(builder, "max_connections", max_connections);
    internal::Put(builder, "allowed_updates", allowed_updates);
    internal::Put(builder, "drop_pending_updates", drop_pending_updates);
    internal::Put(builder, "secret_token", secret_token);

    const auto result = client->CallResult("setWebhook", builder.ExtractValue(), timeouts.webhook);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteWebhook(Optional<Boolean> drop_pending_updates) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "drop_pending_updates", drop_pending_updates);

    const auto result = client->CallResult("deleteWebhook", builder.ExtractValue(), timeouts.webhook);

    return result.As<Boolean>();
}

WebhookInfo BotApi::GetWebhookInfo() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("getWebhookInfo", builder.ExtractValue(), timeouts.common);

    return result.As<WebhookInfo>();
}

}  // namespace tg
