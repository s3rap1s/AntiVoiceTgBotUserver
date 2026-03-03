#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Message BotApi::SendMessage(
    OneOf<Integer, String> chat_id, String text, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<String> parse_mode,
    Optional<Array<MessageEntity>> entities, Optional<LinkPreviewOptions> link_preview_options,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<SuggestedPostParameters> suggested_post_parameters,
    Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "text", text);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "entities", entities);
    internal::Put(builder, "link_preview_options", link_preview_options);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendMessage", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::ForwardMessage(OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id, Integer message_id,
                               Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id,
                               Optional<Integer> video_start_timestamp, Optional<Boolean> disable_notification,
                               Optional<Boolean> protect_content, Optional<String> message_effect_id,
                               Optional<SuggestedPostParameters> suggested_post_parameters) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "from_chat_id", from_chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "video_start_timestamp", video_start_timestamp);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);

    const auto result = client->CallResult("forwardMessage", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Array<MessageId> BotApi::ForwardMessages(OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id,
                                         Array<Integer> message_ids, Optional<Integer> message_thread_id,
                                         Optional<Integer> direct_messages_topic_id,
                                         Optional<Boolean> disable_notification, Optional<Boolean> protect_content) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "from_chat_id", from_chat_id);
    internal::Put(builder, "message_ids", message_ids);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);

    const auto result = client->CallResult("forwardMessages", builder.ExtractValue(), timeouts.common);

    Array<MessageId> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<MessageId>());
    }
    return out;
}

MessageId BotApi::CopyMessage(
    OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id, Integer message_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id,
    Optional<Integer> video_start_timestamp, Optional<String> caption, Optional<String> parse_mode,
    Optional<Array<MessageEntity>> caption_entities, Optional<Boolean> show_caption_above_media,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<SuggestedPostParameters> suggested_post_parameters,
    Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "from_chat_id", from_chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "video_start_timestamp", video_start_timestamp);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "show_caption_above_media", show_caption_above_media);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("copyMessage", builder.ExtractValue(), timeouts.common);

    return result.As<MessageId>();
}

Array<MessageId> BotApi::CopyMessages(OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id,
                                      Array<Integer> message_ids, Optional<Integer> message_thread_id,
                                      Optional<Integer> direct_messages_topic_id,
                                      Optional<Boolean> disable_notification, Optional<Boolean> protect_content,
                                      Optional<Boolean> remove_caption) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "from_chat_id", from_chat_id);
    internal::Put(builder, "message_ids", message_ids);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "remove_caption", remove_caption);

    const auto result = client->CallResult("copyMessages", builder.ExtractValue(), timeouts.common);

    Array<MessageId> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<MessageId>());
    }
    return out;
}

OneOf<Message, Boolean> BotApi::EditMessageText(String text, Optional<String> business_connection_id,
                                                Optional<OneOf<Integer, String>> chat_id, Optional<Integer> message_id,
                                                Optional<String> inline_message_id, Optional<String> parse_mode,
                                                Optional<Array<MessageEntity>> entities,
                                                Optional<LinkPreviewOptions> link_preview_options,
                                                Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "text", text);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "entities", entities);
    internal::Put(builder, "link_preview_options", link_preview_options);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("editMessageText", builder.ExtractValue(), timeouts.common);

    if (result.IsBool()) {
        return result.As<Boolean>();
    }
    return result.As<Message>();
}

OneOf<Message, Boolean> BotApi::EditMessageCaption(Optional<String> business_connection_id,
                                                   Optional<OneOf<Integer, String>> chat_id,
                                                   Optional<Integer> message_id, Optional<String> inline_message_id,
                                                   Optional<String> caption, Optional<String> parse_mode,
                                                   Optional<Array<MessageEntity>> caption_entities,
                                                   Optional<Boolean> show_caption_above_media,
                                                   Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "show_caption_above_media", show_caption_above_media);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("editMessageCaption", builder.ExtractValue(), timeouts.common);

    if (result.IsBool()) {
        return result.As<Boolean>();
    }
    return result.As<Message>();
}

OneOf<Message, Boolean> BotApi::EditMessageReplyMarkup(Optional<String> business_connection_id,
                                                       Optional<OneOf<Integer, String>> chat_id,
                                                       Optional<Integer> message_id, Optional<String> inline_message_id,
                                                       Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("editMessageReplyMarkup", builder.ExtractValue(), timeouts.common);

    if (result.IsBool()) {
        return result.As<Boolean>();
    }
    return result.As<Message>();
}

Boolean BotApi::DeleteMessage(OneOf<Integer, String> chat_id, Integer message_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);

    const auto result = client->CallResult("deleteMessage", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteMessages(OneOf<Integer, String> chat_id, Array<Integer> message_ids) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_ids", message_ids);

    const auto result = client->CallResult("deleteMessages", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
