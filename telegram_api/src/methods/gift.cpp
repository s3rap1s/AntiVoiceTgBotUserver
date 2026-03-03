#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Gifts BotApi::GetAvailableGifts() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("getAvailableGifts", builder.ExtractValue(), timeouts.common);

    return result.As<Gifts>();
}

Boolean BotApi::SendGift(String gift_id, Optional<Integer> user_id, Optional<OneOf<Integer, String>> chat_id,
                         Optional<Boolean> pay_for_upgrade, Optional<String> text, Optional<String> text_parse_mode,
                         Optional<Array<MessageEntity>> text_entities) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "gift_id", gift_id);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "pay_for_upgrade", pay_for_upgrade);
    internal::Put(builder, "text", text);
    internal::Put(builder, "text_parse_mode", text_parse_mode);
    internal::Put(builder, "text_entities", text_entities);

    const auto result = client->CallResult("sendGift", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::GiftPremiumSubscription(Integer user_id, Integer month_count, Integer star_count, Optional<String> text,
                                        Optional<String> text_parse_mode,
                                        Optional<Array<MessageEntity>> text_entities) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "month_count", month_count);
    internal::Put(builder, "star_count", star_count);
    internal::Put(builder, "text", text);
    internal::Put(builder, "text_parse_mode", text_parse_mode);
    internal::Put(builder, "text_entities", text_entities);

    const auto result = client->CallResult("giftPremiumSubscription", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
