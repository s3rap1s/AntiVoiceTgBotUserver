#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Message BotApi::SendPhoto(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> photo, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<String> caption,
    Optional<String> parse_mode, Optional<Array<MessageEntity>> caption_entities,
    Optional<Boolean> show_caption_above_media, Optional<Boolean> has_spoiler, Optional<Boolean> disable_notification,
    Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "photo", photo);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "show_caption_above_media", show_caption_above_media);
    internal::Put(builder, "has_spoiler", has_spoiler);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendPhoto", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendAudio(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> audio, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<String> caption,
    Optional<String> parse_mode, Optional<Array<MessageEntity>> caption_entities, Optional<Integer> duration,
    Optional<String> performer, Optional<String> title, Optional<OneOf<InputFile, String>> thumbnail,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<SuggestedPostParameters> suggested_post_parameters,
    Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "audio", audio);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "duration", duration);
    internal::Put(builder, "performer", performer);
    internal::Put(builder, "title", title);
    internal::Put(builder, "thumbnail", thumbnail);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendAudio", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendDocument(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> document, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id,
    Optional<OneOf<InputFile, String>> thumbnail, Optional<String> caption, Optional<String> parse_mode,
    Optional<Array<MessageEntity>> caption_entities, Optional<Boolean> disable_content_type_detection,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<SuggestedPostParameters> suggested_post_parameters,
    Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "document", document);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "thumbnail", thumbnail);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "disable_content_type_detection", disable_content_type_detection);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendDocument", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendVideo(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> video, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<Integer> duration,
    Optional<Integer> width, Optional<Integer> height, Optional<OneOf<InputFile, String>> thumbnail,
    Optional<OneOf<InputFile, String>> cover, Optional<Integer> start_timestamp, Optional<String> caption,
    Optional<String> parse_mode, Optional<Array<MessageEntity>> caption_entities,
    Optional<Boolean> show_caption_above_media, Optional<Boolean> has_spoiler, Optional<Boolean> supports_streaming,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<SuggestedPostParameters> suggested_post_parameters,
    Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "video", video);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "duration", duration);
    internal::Put(builder, "width", width);
    internal::Put(builder, "height", height);
    internal::Put(builder, "thumbnail", thumbnail);
    internal::Put(builder, "cover", cover);
    internal::Put(builder, "start_timestamp", start_timestamp);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "show_caption_above_media", show_caption_above_media);
    internal::Put(builder, "has_spoiler", has_spoiler);
    internal::Put(builder, "supports_streaming", supports_streaming);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendVideo", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendAnimation(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> animation, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<Integer> duration,
    Optional<Integer> width, Optional<Integer> height, Optional<OneOf<InputFile, String>> thumbnail,
    Optional<String> caption, Optional<String> parse_mode, Optional<Array<MessageEntity>> caption_entities,
    Optional<Boolean> show_caption_above_media, Optional<Boolean> has_spoiler, Optional<Boolean> disable_notification,
    Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "animation", animation);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "duration", duration);
    internal::Put(builder, "width", width);
    internal::Put(builder, "height", height);
    internal::Put(builder, "thumbnail", thumbnail);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "show_caption_above_media", show_caption_above_media);
    internal::Put(builder, "has_spoiler", has_spoiler);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendAnimation", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendVoice(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> voice, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<String> caption,
    Optional<String> parse_mode, Optional<Array<MessageEntity>> caption_entities, Optional<Integer> duration,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<SuggestedPostParameters> suggested_post_parameters,
    Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "voice", voice);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "duration", duration);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendVoice", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendVideoNote(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> video_note, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<Integer> duration,
    Optional<Integer> length, Optional<OneOf<InputFile, String>> thumbnail, Optional<Boolean> disable_notification,
    Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "video_note", video_note);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "duration", duration);
    internal::Put(builder, "length", length);
    internal::Put(builder, "thumbnail", thumbnail);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendVideoNote", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendPaidMedia(
    OneOf<Integer, String> chat_id, Integer star_count, Array<InputPaidMedia> media,
    Optional<String> business_connection_id, Optional<Integer> message_thread_id,
    Optional<Integer> direct_messages_topic_id, Optional<String> payload, Optional<String> caption,
    Optional<String> parse_mode, Optional<Array<MessageEntity>> caption_entities,
    Optional<Boolean> show_caption_above_media, Optional<Boolean> disable_notification,
    Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "star_count", star_count);
    internal::Put(builder, "media", media);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "payload", payload);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "show_caption_above_media", show_caption_above_media);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendPaidMedia", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Array<Message> BotApi::SendMediaGroup(
    OneOf<Integer, String> chat_id,
    Array<OneOf<InputMediaAudio, InputMediaDocument, InputMediaPhoto, InputMediaVideo>> media,
    Optional<String> business_connection_id, Optional<Integer> message_thread_id,
    Optional<Integer> direct_messages_topic_id, Optional<Boolean> disable_notification,
    Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<ReplyParameters> reply_parameters) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "media", media);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "reply_parameters", reply_parameters);

    const auto result = client->CallResult("sendMediaGroup", builder.ExtractValue(), timeouts.common);

    Array<Message> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<Message>());
    }
    return out;
}

Message BotApi::SendLocation(
    OneOf<Integer, String> chat_id, Float latitude, Float longitude, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id,
    Optional<Float> horizontal_accuracy, Optional<Integer> live_period, Optional<Integer> heading,
    Optional<Integer> proximity_alert_radius, Optional<Boolean> disable_notification, Optional<Boolean> protect_content,
    Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "latitude", latitude);
    internal::Put(builder, "longitude", longitude);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "horizontal_accuracy", horizontal_accuracy);
    internal::Put(builder, "live_period", live_period);
    internal::Put(builder, "heading", heading);
    internal::Put(builder, "proximity_alert_radius", proximity_alert_radius);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendLocation", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendVenue(
    OneOf<Integer, String> chat_id, Float latitude, Float longitude, String title, String address,
    Optional<String> business_connection_id, Optional<Integer> message_thread_id,
    Optional<Integer> direct_messages_topic_id, Optional<String> foursquare_id, Optional<String> foursquare_type,
    Optional<String> google_place_id, Optional<String> google_place_type, Optional<Boolean> disable_notification,
    Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "latitude", latitude);
    internal::Put(builder, "longitude", longitude);
    internal::Put(builder, "title", title);
    internal::Put(builder, "address", address);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "foursquare_id", foursquare_id);
    internal::Put(builder, "foursquare_type", foursquare_type);
    internal::Put(builder, "google_place_id", google_place_id);
    internal::Put(builder, "google_place_type", google_place_type);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendVenue", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendContact(
    OneOf<Integer, String> chat_id, String phone_number, String first_name, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<String> last_name,
    Optional<String> vcard, Optional<Boolean> disable_notification, Optional<Boolean> protect_content,
    Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "phone_number", phone_number);
    internal::Put(builder, "first_name", first_name);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "last_name", last_name);
    internal::Put(builder, "vcard", vcard);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendContact", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendPoll(
    OneOf<Integer, String> chat_id, String question, Array<InputPollOption> options,
    Optional<String> business_connection_id, Optional<Integer> message_thread_id, Optional<String> question_parse_mode,
    Optional<Array<MessageEntity>> question_entities, Optional<Boolean> is_anonymous, Optional<String> type,
    Optional<Boolean> allows_multiple_answers, Optional<Integer> correct_option_id, Optional<String> explanation,
    Optional<String> explanation_parse_mode, Optional<Array<MessageEntity>> explanation_entities,
    Optional<Integer> open_period, Optional<Integer> close_date, Optional<Boolean> is_closed,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "question", question);
    internal::Put(builder, "options", options);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "question_parse_mode", question_parse_mode);
    internal::Put(builder, "question_entities", question_entities);
    internal::Put(builder, "is_anonymous", is_anonymous);
    internal::Put(builder, "type", type);
    internal::Put(builder, "allows_multiple_answers", allows_multiple_answers);
    internal::Put(builder, "correct_option_id", correct_option_id);
    internal::Put(builder, "explanation", explanation);
    internal::Put(builder, "explanation_parse_mode", explanation_parse_mode);
    internal::Put(builder, "explanation_entities", explanation_entities);
    internal::Put(builder, "open_period", open_period);
    internal::Put(builder, "close_date", close_date);
    internal::Put(builder, "is_closed", is_closed);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendPoll", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendChecklist(String business_connection_id, Integer chat_id, InputChecklist checklist,
                              Optional<Boolean> disable_notification, Optional<Boolean> protect_content,
                              Optional<String> message_effect_id, Optional<ReplyParameters> reply_parameters,
                              Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "checklist", checklist);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendChecklist", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Message BotApi::SendDice(
    OneOf<Integer, String> chat_id, Optional<String> business_connection_id, Optional<Integer> message_thread_id,
    Optional<Integer> direct_messages_topic_id, Optional<String> emoji, Optional<Boolean> disable_notification,
    Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast, Optional<String> message_effect_id,
    Optional<SuggestedPostParameters> suggested_post_parameters, Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "emoji", emoji);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendDice", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

Boolean BotApi::SendMessageDraft(Integer chat_id, Integer draft_id, String text, Optional<Integer> message_thread_id,
                                 Optional<String> parse_mode, Optional<Array<MessageEntity>> entities) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "draft_id", draft_id);
    internal::Put(builder, "text", text);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "entities", entities);

    const auto result = client->CallResult("sendMessageDraft", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SendChatAction(OneOf<Integer, String> chat_id, String action, Optional<String> business_connection_id,
                               Optional<Integer> message_thread_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "action", action);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);

    const auto result = client->CallResult("sendChatAction", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

OneOf<Message, Boolean> BotApi::EditMessageMedia(InputMedia media, Optional<String> business_connection_id,
                                                 Optional<OneOf<Integer, String>> chat_id, Optional<Integer> message_id,
                                                 Optional<String> inline_message_id,
                                                 Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "media", media);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("editMessageMedia", builder.ExtractValue(), timeouts.common);

    if (result.IsBool()) {
        return result.As<Boolean>();
    }
    return result.As<Message>();
}

OneOf<Message, Boolean> BotApi::EditMessageLiveLocation(
    Float latitude, Float longitude, Optional<String> business_connection_id, Optional<OneOf<Integer, String>> chat_id,
    Optional<Integer> message_id, Optional<String> inline_message_id, Optional<Integer> live_period,
    Optional<Float> horizontal_accuracy, Optional<Integer> heading, Optional<Integer> proximity_alert_radius,
    Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "latitude", latitude);
    internal::Put(builder, "longitude", longitude);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);
    internal::Put(builder, "live_period", live_period);
    internal::Put(builder, "horizontal_accuracy", horizontal_accuracy);
    internal::Put(builder, "heading", heading);
    internal::Put(builder, "proximity_alert_radius", proximity_alert_radius);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("editMessageLiveLocation", builder.ExtractValue(), timeouts.common);

    if (result.IsBool()) {
        return result.As<Boolean>();
    }
    return result.As<Message>();
}

OneOf<Message, Boolean> BotApi::StopMessageLiveLocation(Optional<String> business_connection_id,
                                                        Optional<OneOf<Integer, String>> chat_id,
                                                        Optional<Integer> message_id,
                                                        Optional<String> inline_message_id,
                                                        Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "inline_message_id", inline_message_id);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("stopMessageLiveLocation", builder.ExtractValue(), timeouts.common);

    if (result.IsBool()) {
        return result.As<Boolean>();
    }
    return result.As<Message>();
}

Poll BotApi::StopPoll(OneOf<Integer, String> chat_id, Integer message_id, Optional<String> business_connection_id,
                      Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("stopPoll", builder.ExtractValue(), timeouts.common);

    return result.As<Poll>();
}

Message BotApi::EditMessageChecklist(String business_connection_id, Integer chat_id, Integer message_id,
                                     InputChecklist checklist, Optional<InlineKeyboardMarkup> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "checklist", checklist);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("editMessageChecklist", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

File BotApi::GetFile(String file_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "file_id", file_id);

    const auto result = client->CallResult("getFile", builder.ExtractValue(), timeouts.common);

    return result.As<File>();
}

}  // namespace tg
