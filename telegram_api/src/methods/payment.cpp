#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Message BotApi::SendInvoice(OneOf<Integer, String> chat_id, String title, String description, String payload,
                            String currency, Array<LabeledPrice> prices, Optional<Integer> message_thread_id,
                            Optional<Integer> direct_messages_topic_id, Optional<String> provider_token,
                            Optional<Integer> max_tip_amount, Optional<Array<Integer>> suggested_tip_amounts,
                            Optional<String> start_parameter, Optional<String> provider_data,
                            Optional<String> photo_url, Optional<Integer> photo_size, Optional<Integer> photo_width,
                            Optional<Integer> photo_height, Optional<Boolean> need_name,
                            Optional<Boolean> need_phone_number, Optional<Boolean> need_email,
                            Optional<Boolean> need_shipping_address, Optional<Boolean> send_phone_number_to_provider,
                            Optional<Boolean> send_email_to_provider, Optional<Boolean> is_flexible,
                            Optional<Boolean> disable_notification, Optional<Boolean> protect_content,
                            Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
                            Optional<SuggestedPostParameters> suggested_post_parameters,
                            Optional<ReplyParameters> reply_parameters, Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "title", title);
    internal::Put(builder, "description", description);
    internal::Put(builder, "payload", payload);
    internal::Put(builder, "currency", currency);
    internal::Put(builder, "prices", prices);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "provider_token", provider_token);
    internal::Put(builder, "max_tip_amount", max_tip_amount);
    internal::Put(builder, "suggested_tip_amounts", suggested_tip_amounts);
    internal::Put(builder, "start_parameter", start_parameter);
    internal::Put(builder, "provider_data", provider_data);
    internal::Put(builder, "photo_url", photo_url);
    internal::Put(builder, "photo_size", photo_size);
    internal::Put(builder, "photo_width", photo_width);
    internal::Put(builder, "photo_height", photo_height);
    internal::Put(builder, "need_name", need_name);
    internal::Put(builder, "need_phone_number", need_phone_number);
    internal::Put(builder, "need_email", need_email);
    internal::Put(builder, "need_shipping_address", need_shipping_address);
    internal::Put(builder, "send_phone_number_to_provider", send_phone_number_to_provider);
    internal::Put(builder, "send_email_to_provider", send_email_to_provider);
    internal::Put(builder, "is_flexible", is_flexible);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendInvoice", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

String BotApi::CreateInvoiceLink(String title, String description, String payload, String currency,
                                 Array<LabeledPrice> prices, Optional<String> business_connection_id,
                                 Optional<String> provider_token, Optional<Integer> subscription_period,
                                 Optional<Integer> max_tip_amount, Optional<Array<Integer>> suggested_tip_amounts,
                                 Optional<String> provider_data, Optional<String> photo_url,
                                 Optional<Integer> photo_size, Optional<Integer> photo_width,
                                 Optional<Integer> photo_height, Optional<Boolean> need_name,
                                 Optional<Boolean> need_phone_number, Optional<Boolean> need_email,
                                 Optional<Boolean> need_shipping_address,
                                 Optional<Boolean> send_phone_number_to_provider,
                                 Optional<Boolean> send_email_to_provider, Optional<Boolean> is_flexible) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "title", title);
    internal::Put(builder, "description", description);
    internal::Put(builder, "payload", payload);
    internal::Put(builder, "currency", currency);
    internal::Put(builder, "prices", prices);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "provider_token", provider_token);
    internal::Put(builder, "subscription_period", subscription_period);
    internal::Put(builder, "max_tip_amount", max_tip_amount);
    internal::Put(builder, "suggested_tip_amounts", suggested_tip_amounts);
    internal::Put(builder, "provider_data", provider_data);
    internal::Put(builder, "photo_url", photo_url);
    internal::Put(builder, "photo_size", photo_size);
    internal::Put(builder, "photo_width", photo_width);
    internal::Put(builder, "photo_height", photo_height);
    internal::Put(builder, "need_name", need_name);
    internal::Put(builder, "need_phone_number", need_phone_number);
    internal::Put(builder, "need_email", need_email);
    internal::Put(builder, "need_shipping_address", need_shipping_address);
    internal::Put(builder, "send_phone_number_to_provider", send_phone_number_to_provider);
    internal::Put(builder, "send_email_to_provider", send_email_to_provider);
    internal::Put(builder, "is_flexible", is_flexible);

    const auto result = client->CallResult("createInvoiceLink", builder.ExtractValue(), timeouts.common);

    return result.As<String>();
}

Boolean BotApi::AnswerShippingQuery(String shipping_query_id, Boolean ok,
                                    Optional<Array<ShippingOption>> shipping_options, Optional<String> error_message) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "shipping_query_id", shipping_query_id);
    internal::Put(builder, "ok", ok);
    internal::Put(builder, "shipping_options", shipping_options);
    internal::Put(builder, "error_message", error_message);

    const auto result = client->CallResult("answerShippingQuery", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::AnswerPreCheckoutQuery(String pre_checkout_query_id, Boolean ok, Optional<String> error_message) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "pre_checkout_query_id", pre_checkout_query_id);
    internal::Put(builder, "ok", ok);
    internal::Put(builder, "error_message", error_message);

    const auto result = client->CallResult("answerPreCheckoutQuery", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

StarAmount BotApi::GetMyStarBalance() {
    auto builder = internal::MakeObject();

    const auto result = client->CallResult("getMyStarBalance", builder.ExtractValue(), timeouts.common);

    return result.As<StarAmount>();
}

StarTransactions BotApi::GetStarTransactions(Optional<Integer> offset, Optional<Integer> limit) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "offset", offset);
    internal::Put(builder, "limit", limit);

    const auto result = client->CallResult("getStarTransactions", builder.ExtractValue(), timeouts.common);

    return result.As<StarTransactions>();
}

Boolean BotApi::RefundStarPayment(Integer user_id, String telegram_payment_charge_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "telegram_payment_charge_id", telegram_payment_charge_id);

    const auto result = client->CallResult("refundStarPayment", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::EditUserStarSubscription(Integer user_id, String telegram_payment_charge_id, Boolean is_canceled) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "telegram_payment_charge_id", telegram_payment_charge_id);
    internal::Put(builder, "is_canceled", is_canceled);

    const auto result = client->CallResult("editUserStarSubscription", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
