#pragma once

#include <chrono>
#include <memory>
#include <string>

#include <userver/clients/http/client.hpp>
#include <userver/formats/json/value.hpp>

#include <tg/types/accepted_gift_types.hpp>
#include <tg/types/bot_command.hpp>
#include <tg/types/bot_command_scope.hpp>
#include <tg/types/bot_description.hpp>
#include <tg/types/bot_name.hpp>
#include <tg/types/bot_short_description.hpp>
#include <tg/types/business_connection.hpp>
#include <tg/types/chat_administrator_rights.hpp>
#include <tg/types/chat_full_info.hpp>
#include <tg/types/chat_invite_link.hpp>
#include <tg/types/chat_member.hpp>
#include <tg/types/chat_permissions.hpp>
#include <tg/types/common.hpp>
#include <tg/types/file.hpp>
#include <tg/types/force_reply.hpp>
#include <tg/types/forum_topic.hpp>
#include <tg/types/game_high_score.hpp>
#include <tg/types/gifts.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result.hpp>
#include <tg/types/inline_query_result_button.hpp>
#include <tg/types/input_checklist.hpp>
#include <tg/types/input_file.hpp>
#include <tg/types/input_media.hpp>
#include <tg/types/input_media_audio.hpp>
#include <tg/types/input_media_document.hpp>
#include <tg/types/input_media_photo.hpp>
#include <tg/types/input_media_video.hpp>
#include <tg/types/input_paid_media.hpp>
#include <tg/types/input_poll_option.hpp>
#include <tg/types/input_profile_photo.hpp>
#include <tg/types/input_sticker.hpp>
#include <tg/types/input_story_content.hpp>
#include <tg/types/labeled_price.hpp>
#include <tg/types/link_preview_options.hpp>
#include <tg/types/mask_position.hpp>
#include <tg/types/menu_button.hpp>
#include <tg/types/message.hpp>
#include <tg/types/message_id.hpp>
#include <tg/types/owned_gifts.hpp>
#include <tg/types/passport_element_error.hpp>
#include <tg/types/poll.hpp>
#include <tg/types/prepared_inline_message.hpp>
#include <tg/types/reaction_type.hpp>
#include <tg/types/reply_keyboard_markup.hpp>
#include <tg/types/reply_keyboard_remove.hpp>
#include <tg/types/reply_parameters.hpp>
#include <tg/types/sent_web_app_message.hpp>
#include <tg/types/shipping_option.hpp>
#include <tg/types/star_amount.hpp>
#include <tg/types/star_transactions.hpp>
#include <tg/types/sticker.hpp>
#include <tg/types/sticker_set.hpp>
#include <tg/types/story.hpp>
#include <tg/types/story_area.hpp>
#include <tg/types/suggested_post_parameters.hpp>
#include <tg/types/update.hpp>
#include <tg/types/user_chat_boosts.hpp>
#include <tg/types/user_profile_audios.hpp>
#include <tg/types/user_profile_photos.hpp>
#include <tg/types/webhook_info.hpp>

namespace tg {

namespace internal {
class JsonClient;
}

class BotApi final {
   public:
    using Json = userver::formats::json::Value;

    explicit BotApi(userver::clients::http::Client& http, std::string token);
    ~BotApi();

    // Update
    Array<Update> GetUpdates(Optional<Integer> offset = std::nullopt, Optional<Integer> limit = std::nullopt,
                             Optional<Integer> timeout = std::nullopt,
                             Optional<Array<String>> allowed_updates = std::nullopt);

    Boolean SetWebhook(String url, Optional<InputFile> certificate = std::nullopt,
                       Optional<String> ip_address = std::nullopt, Optional<Integer> max_connections = std::nullopt,
                       Optional<Array<String>> allowed_updates = std::nullopt,
                       Optional<Boolean> drop_pending_updates = std::nullopt,
                       Optional<String> secret_token = std::nullopt);

    Boolean DeleteWebhook(Optional<Boolean> drop_pending_updates = std::nullopt);

    WebhookInfo GetWebhookInfo();

    // Bot
    User GetMe();

    Boolean LogOut();

    Boolean Close();

    BusinessConnection GetBusinessConnection(String business_connection_id);

    Boolean SetMyCommands(Array<BotCommand> commands, Optional<BotCommandScope> scope = std::nullopt,
                          Optional<String> language_code = std::nullopt);

    Boolean DeleteMyCommands(Optional<BotCommandScope> scope = std::nullopt,
                             Optional<String> language_code = std::nullopt);

    Array<BotCommand> GetMyCommands(Optional<BotCommandScope> scope = std::nullopt,
                                    Optional<String> language_code = std::nullopt);

    Boolean SetMyName(Optional<String> name = std::nullopt, Optional<String> language_code = std::nullopt);

    BotName GetMyName(Optional<String> language_code = std::nullopt);

    Boolean SetMyDescription(Optional<String> description = std::nullopt,
                             Optional<String> language_code = std::nullopt);

    BotDescription GetMyDescription(Optional<String> language_code = std::nullopt);

    Boolean SetMyShortDescription(Optional<String> short_description = std::nullopt,
                                  Optional<String> language_code = std::nullopt);

    BotShortDescription GetMyShortDescription(Optional<String> language_code = std::nullopt);

    Boolean SetMyProfilePhoto(InputProfilePhoto photo);

    Boolean RemoveMyProfilePhoto();

    Boolean SetChatMenuButton(Optional<Integer> chat_id = std::nullopt,
                              Optional<MenuButton> menu_button = std::nullopt);

    MenuButton GetChatMenuButton(Optional<Integer> chat_id = std::nullopt);

    // Message
    Message SendMessage(
        OneOf<Integer, String> chat_id, String text, Optional<String> business_connection_id = std::nullopt,
        Optional<Integer> message_thread_id = std::nullopt, Optional<Integer> direct_messages_topic_id = std::nullopt,
        Optional<String> parse_mode = std::nullopt, Optional<Array<MessageEntity>> entities = std::nullopt,
        Optional<LinkPreviewOptions> link_preview_options = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message ForwardMessage(OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id, Integer message_id,
                           Optional<Integer> message_thread_id = std::nullopt,
                           Optional<Integer> direct_messages_topic_id = std::nullopt,
                           Optional<Integer> video_start_timestamp = std::nullopt,
                           Optional<Boolean> disable_notification = std::nullopt,
                           Optional<Boolean> protect_content = std::nullopt,
                           Optional<String> message_effect_id = std::nullopt,
                           Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt);

    Array<MessageId> ForwardMessages(OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id,
                                     Array<Integer> message_ids, Optional<Integer> message_thread_id = std::nullopt,
                                     Optional<Integer> direct_messages_topic_id = std::nullopt,
                                     Optional<Boolean> disable_notification = std::nullopt,
                                     Optional<Boolean> protect_content = std::nullopt);

    MessageId CopyMessage(
        OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id, Integer message_id,
        Optional<Integer> message_thread_id = std::nullopt, Optional<Integer> direct_messages_topic_id = std::nullopt,
        Optional<Integer> video_start_timestamp = std::nullopt, Optional<String> caption = std::nullopt,
        Optional<String> parse_mode = std::nullopt, Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Boolean> show_caption_above_media = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Array<MessageId> CopyMessages(OneOf<Integer, String> chat_id, OneOf<Integer, String> from_chat_id,
                                  Array<Integer> message_ids, Optional<Integer> message_thread_id = std::nullopt,
                                  Optional<Integer> direct_messages_topic_id = std::nullopt,
                                  Optional<Boolean> disable_notification = std::nullopt,
                                  Optional<Boolean> protect_content = std::nullopt,
                                  Optional<Boolean> remove_caption = std::nullopt);

    OneOf<Message, Boolean> EditMessageText(String text, Optional<String> business_connection_id = std::nullopt,
                                            Optional<OneOf<Integer, String>> chat_id = std::nullopt,
                                            Optional<Integer> message_id = std::nullopt,
                                            Optional<String> inline_message_id = std::nullopt,
                                            Optional<String> parse_mode = std::nullopt,
                                            Optional<Array<MessageEntity>> entities = std::nullopt,
                                            Optional<LinkPreviewOptions> link_preview_options = std::nullopt,
                                            Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    OneOf<Message, Boolean> EditMessageCaption(Optional<String> business_connection_id = std::nullopt,
                                               Optional<OneOf<Integer, String>> chat_id = std::nullopt,
                                               Optional<Integer> message_id = std::nullopt,
                                               Optional<String> inline_message_id = std::nullopt,
                                               Optional<String> caption = std::nullopt,
                                               Optional<String> parse_mode = std::nullopt,
                                               Optional<Array<MessageEntity>> caption_entities = std::nullopt,
                                               Optional<Boolean> show_caption_above_media = std::nullopt,
                                               Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    OneOf<Message, Boolean> EditMessageReplyMarkup(Optional<String> business_connection_id = std::nullopt,
                                                   Optional<OneOf<Integer, String>> chat_id = std::nullopt,
                                                   Optional<Integer> message_id = std::nullopt,
                                                   Optional<String> inline_message_id = std::nullopt,
                                                   Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    Boolean DeleteMessage(OneOf<Integer, String> chat_id, Integer message_id);

    Boolean DeleteMessages(OneOf<Integer, String> chat_id, Array<Integer> message_ids);

    // Media
    Message SendPhoto(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> photo,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> caption = std::nullopt,
        Optional<String> parse_mode = std::nullopt, Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Boolean> show_caption_above_media = std::nullopt, Optional<Boolean> has_spoiler = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendAudio(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> audio,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> caption = std::nullopt,
        Optional<String> parse_mode = std::nullopt, Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Integer> duration = std::nullopt, Optional<String> performer = std::nullopt,
        Optional<String> title = std::nullopt, Optional<OneOf<InputFile, String>> thumbnail = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendDocument(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> document,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt,
        Optional<OneOf<InputFile, String>> thumbnail = std::nullopt, Optional<String> caption = std::nullopt,
        Optional<String> parse_mode = std::nullopt, Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Boolean> disable_content_type_detection = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendVideo(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> video,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<Integer> duration = std::nullopt,
        Optional<Integer> width = std::nullopt, Optional<Integer> height = std::nullopt,
        Optional<OneOf<InputFile, String>> thumbnail = std::nullopt,
        Optional<OneOf<InputFile, String>> cover = std::nullopt, Optional<Integer> start_timestamp = std::nullopt,
        Optional<String> caption = std::nullopt, Optional<String> parse_mode = std::nullopt,
        Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Boolean> show_caption_above_media = std::nullopt, Optional<Boolean> has_spoiler = std::nullopt,
        Optional<Boolean> supports_streaming = std::nullopt, Optional<Boolean> disable_notification = std::nullopt,
        Optional<Boolean> protect_content = std::nullopt, Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendAnimation(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> animation,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<Integer> duration = std::nullopt,
        Optional<Integer> width = std::nullopt, Optional<Integer> height = std::nullopt,
        Optional<OneOf<InputFile, String>> thumbnail = std::nullopt, Optional<String> caption = std::nullopt,
        Optional<String> parse_mode = std::nullopt, Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Boolean> show_caption_above_media = std::nullopt, Optional<Boolean> has_spoiler = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendVoice(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> voice,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> caption = std::nullopt,
        Optional<String> parse_mode = std::nullopt, Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Integer> duration = std::nullopt, Optional<Boolean> disable_notification = std::nullopt,
        Optional<Boolean> protect_content = std::nullopt, Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendVideoNote(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> video_note,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<Integer> duration = std::nullopt,
        Optional<Integer> length = std::nullopt, Optional<OneOf<InputFile, String>> thumbnail = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendPaidMedia(
        OneOf<Integer, String> chat_id, Integer star_count, Array<InputPaidMedia> media,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> payload = std::nullopt,
        Optional<String> caption = std::nullopt, Optional<String> parse_mode = std::nullopt,
        Optional<Array<MessageEntity>> caption_entities = std::nullopt,
        Optional<Boolean> show_caption_above_media = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Array<Message> SendMediaGroup(
        OneOf<Integer, String> chat_id,
        Array<OneOf<InputMediaAudio, InputMediaDocument, InputMediaPhoto, InputMediaVideo>> media,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt);

    Message SendLocation(
        OneOf<Integer, String> chat_id, Float latitude, Float longitude,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<Float> horizontal_accuracy = std::nullopt,
        Optional<Integer> live_period = std::nullopt, Optional<Integer> heading = std::nullopt,
        Optional<Integer> proximity_alert_radius = std::nullopt, Optional<Boolean> disable_notification = std::nullopt,
        Optional<Boolean> protect_content = std::nullopt, Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendVenue(
        OneOf<Integer, String> chat_id, Float latitude, Float longitude, String title, String address,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> foursquare_id = std::nullopt,
        Optional<String> foursquare_type = std::nullopt, Optional<String> google_place_id = std::nullopt,
        Optional<String> google_place_type = std::nullopt, Optional<Boolean> disable_notification = std::nullopt,
        Optional<Boolean> protect_content = std::nullopt, Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendContact(
        OneOf<Integer, String> chat_id, String phone_number, String first_name,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> last_name = std::nullopt,
        Optional<String> vcard = std::nullopt, Optional<Boolean> disable_notification = std::nullopt,
        Optional<Boolean> protect_content = std::nullopt, Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendPoll(
        OneOf<Integer, String> chat_id, String question, Array<InputPollOption> options,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<String> question_parse_mode = std::nullopt,
        Optional<Array<MessageEntity>> question_entities = std::nullopt, Optional<Boolean> is_anonymous = std::nullopt,
        Optional<String> type = std::nullopt, Optional<Boolean> allows_multiple_answers = std::nullopt,
        Optional<Integer> correct_option_id = std::nullopt, Optional<String> explanation = std::nullopt,
        Optional<String> explanation_parse_mode = std::nullopt,
        Optional<Array<MessageEntity>> explanation_entities = std::nullopt,
        Optional<Integer> open_period = std::nullopt, Optional<Integer> close_date = std::nullopt,
        Optional<Boolean> is_closed = std::nullopt, Optional<Boolean> disable_notification = std::nullopt,
        Optional<Boolean> protect_content = std::nullopt, Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<String> message_effect_id = std::nullopt, Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Message SendChecklist(String business_connection_id, Integer chat_id, InputChecklist checklist,
                          Optional<Boolean> disable_notification = std::nullopt,
                          Optional<Boolean> protect_content = std::nullopt,
                          Optional<String> message_effect_id = std::nullopt,
                          Optional<ReplyParameters> reply_parameters = std::nullopt,
                          Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    Message SendDice(
        OneOf<Integer, String> chat_id, Optional<String> business_connection_id = std::nullopt,
        Optional<Integer> message_thread_id = std::nullopt, Optional<Integer> direct_messages_topic_id = std::nullopt,
        Optional<String> emoji = std::nullopt, Optional<Boolean> disable_notification = std::nullopt,
        Optional<Boolean> protect_content = std::nullopt, Optional<Boolean> allow_paid_broadcast = std::nullopt,
        Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    Boolean SendMessageDraft(Integer chat_id, Integer draft_id, String text,
                             Optional<Integer> message_thread_id = std::nullopt,
                             Optional<String> parse_mode = std::nullopt,
                             Optional<Array<MessageEntity>> entities = std::nullopt);

    Boolean SendChatAction(OneOf<Integer, String> chat_id, String action,
                           Optional<String> business_connection_id = std::nullopt,
                           Optional<Integer> message_thread_id = std::nullopt);

    OneOf<Message, Boolean> EditMessageMedia(InputMedia media, Optional<String> business_connection_id = std::nullopt,
                                             Optional<OneOf<Integer, String>> chat_id = std::nullopt,
                                             Optional<Integer> message_id = std::nullopt,
                                             Optional<String> inline_message_id = std::nullopt,
                                             Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    OneOf<Message, Boolean> EditMessageLiveLocation(
        Float latitude, Float longitude, Optional<String> business_connection_id = std::nullopt,
        Optional<OneOf<Integer, String>> chat_id = std::nullopt, Optional<Integer> message_id = std::nullopt,
        Optional<String> inline_message_id = std::nullopt, Optional<Integer> live_period = std::nullopt,
        Optional<Float> horizontal_accuracy = std::nullopt, Optional<Integer> heading = std::nullopt,
        Optional<Integer> proximity_alert_radius = std::nullopt,
        Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    OneOf<Message, Boolean> StopMessageLiveLocation(Optional<String> business_connection_id = std::nullopt,
                                                    Optional<OneOf<Integer, String>> chat_id = std::nullopt,
                                                    Optional<Integer> message_id = std::nullopt,
                                                    Optional<String> inline_message_id = std::nullopt,
                                                    Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    Poll StopPoll(OneOf<Integer, String> chat_id, Integer message_id,
                  Optional<String> business_connection_id = std::nullopt,
                  Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    Message EditMessageChecklist(String business_connection_id, Integer chat_id, Integer message_id,
                                 InputChecklist checklist, Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    File GetFile(String file_id);

    // Sticker
    Message SendSticker(
        OneOf<Integer, String> chat_id, OneOf<InputFile, String> sticker,
        Optional<String> business_connection_id = std::nullopt, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> emoji = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup =
            std::nullopt);

    StickerSet GetStickerSet(String name);

    Array<Sticker> GetCustomEmojiStickers(Array<String> custom_emoji_ids);

    File UploadStickerFile(Integer user_id, InputFile sticker, String sticker_format);

    Boolean CreateNewStickerSet(Integer user_id, String name, String title, Array<InputSticker> stickers,
                                Optional<String> sticker_type = std::nullopt,
                                Optional<Boolean> needs_repainting = std::nullopt);

    Boolean AddStickerToSet(Integer user_id, String name, InputSticker sticker);

    Boolean SetStickerPositionInSet(String sticker, Integer position);

    Boolean DeleteStickerFromSet(String sticker);

    Boolean ReplaceStickerInSet(Integer user_id, String name, String old_sticker, InputSticker sticker);

    Boolean SetStickerEmojiList(String sticker, Array<String> emoji_list);

    Boolean SetStickerKeywords(String sticker, Optional<Array<String>> keywords = std::nullopt);

    Boolean SetStickerMaskPosition(String sticker, Optional<MaskPosition> mask_position = std::nullopt);

    Boolean SetStickerSetTitle(String name, String title);

    Boolean SetStickerSetThumbnail(String name, Integer user_id, String format,
                                   Optional<OneOf<InputFile, String>> thumbnail = std::nullopt);

    Boolean SetCustomEmojiStickerSetThumbnail(String name, Optional<String> custom_emoji_id = std::nullopt);

    Boolean DeleteStickerSet(String name);

    // User
    UserProfilePhotos GetUserProfilePhotos(Integer user_id, Optional<Integer> offset = std::nullopt,
                                           Optional<Integer> limit = std::nullopt);

    UserProfileAudios GetUserProfileAudios(Integer user_id, Optional<Integer> offset = std::nullopt,
                                           Optional<Integer> limit = std::nullopt);

    Boolean SetUserEmojiStatus(Integer user_id, Optional<String> emoji_status_custom_emoji_id = std::nullopt,
                               Optional<Integer> emoji_status_expiration_date = std::nullopt);

    Boolean VerifyUser(Integer user_id, Optional<String> custom_description = std::nullopt);

    Boolean RemoveUserVerification(Integer user_id);

    OwnedGifts GetUserGifts(Integer user_id, Optional<Boolean> exclude_unlimited = std::nullopt,
                            Optional<Boolean> exclude_limited_upgradable = std::nullopt,
                            Optional<Boolean> exclude_limited_non_upgradable = std::nullopt,
                            Optional<Boolean> exclude_from_blockchain = std::nullopt,
                            Optional<Boolean> exclude_unique = std::nullopt,
                            Optional<Boolean> sort_by_price = std::nullopt, Optional<String> offset = std::nullopt,
                            Optional<Integer> limit = std::nullopt);

    // Chat
    Boolean SetMessageReaction(OneOf<Integer, String> chat_id, Integer message_id,
                               Optional<Array<ReactionType>> reaction = std::nullopt,
                               Optional<Boolean> is_big = std::nullopt);

    Boolean BanChatMember(OneOf<Integer, String> chat_id, Integer user_id, Optional<Integer> until_date = std::nullopt,
                          Optional<Boolean> revoke_messages = std::nullopt);

    Boolean UnbanChatMember(OneOf<Integer, String> chat_id, Integer user_id,
                            Optional<Boolean> only_if_banned = std::nullopt);

    Boolean RestrictChatMember(OneOf<Integer, String> chat_id, Integer user_id, ChatPermissions permissions,
                               Optional<Boolean> use_independent_chat_permissions = std::nullopt,
                               Optional<Integer> until_date = std::nullopt);

    Boolean PromoteChatMember(
        OneOf<Integer, String> chat_id, Integer user_id, Optional<Boolean> is_anonymous = std::nullopt,
        Optional<Boolean> can_manage_chat = std::nullopt, Optional<Boolean> can_delete_messages = std::nullopt,
        Optional<Boolean> can_manage_video_chats = std::nullopt, Optional<Boolean> can_restrict_members = std::nullopt,
        Optional<Boolean> can_promote_members = std::nullopt, Optional<Boolean> can_change_info = std::nullopt,
        Optional<Boolean> can_invite_users = std::nullopt, Optional<Boolean> can_post_stories = std::nullopt,
        Optional<Boolean> can_edit_stories = std::nullopt, Optional<Boolean> can_delete_stories = std::nullopt,
        Optional<Boolean> can_post_messages = std::nullopt, Optional<Boolean> can_edit_messages = std::nullopt,
        Optional<Boolean> can_pin_messages = std::nullopt, Optional<Boolean> can_manage_topics = std::nullopt,
        Optional<Boolean> can_manage_direct_messages = std::nullopt, Optional<Boolean> can_manage_tags = std::nullopt);

    Boolean SetChatAdministratorCustomTitle(OneOf<Integer, String> chat_id, Integer user_id, String custom_title);

    Boolean SetChatMemberTag(OneOf<Integer, String> chat_id, Integer user_id, Optional<String> tag = std::nullopt);

    Boolean BanChatSenderChat(OneOf<Integer, String> chat_id, Integer sender_chat_id);

    Boolean UnbanChatSenderChat(OneOf<Integer, String> chat_id, Integer sender_chat_id);

    Boolean SetChatPermissions(OneOf<Integer, String> chat_id, ChatPermissions permissions,
                               Optional<Boolean> use_independent_chat_permissions = std::nullopt);

    String ExportChatInviteLink(OneOf<Integer, String> chat_id);

    ChatInviteLink CreateChatInviteLink(OneOf<Integer, String> chat_id, Optional<String> name = std::nullopt,
                                        Optional<Integer> expire_date = std::nullopt,
                                        Optional<Integer> member_limit = std::nullopt,
                                        Optional<Boolean> creates_join_request = std::nullopt);

    ChatInviteLink EditChatInviteLink(OneOf<Integer, String> chat_id, String invite_link,
                                      Optional<String> name = std::nullopt,
                                      Optional<Integer> expire_date = std::nullopt,
                                      Optional<Integer> member_limit = std::nullopt,
                                      Optional<Boolean> creates_join_request = std::nullopt);

    ChatInviteLink CreateChatSubscriptionInviteLink(OneOf<Integer, String> chat_id, Integer subscription_period,
                                                    Integer subscription_price, Optional<String> name = std::nullopt);

    ChatInviteLink EditChatSubscriptionInviteLink(OneOf<Integer, String> chat_id, String invite_link,
                                                  Optional<String> name = std::nullopt);

    ChatInviteLink RevokeChatInviteLink(OneOf<Integer, String> chat_id, String invite_link);

    Boolean ApproveChatJoinRequest(OneOf<Integer, String> chat_id, Integer user_id);

    Boolean DeclineChatJoinRequest(OneOf<Integer, String> chat_id, Integer user_id);

    Boolean SetChatPhoto(OneOf<Integer, String> chat_id, InputFile photo);

    Boolean DeleteChatPhoto(OneOf<Integer, String> chat_id);

    Boolean SetChatTitle(OneOf<Integer, String> chat_id, String title);

    Boolean SetChatDescription(OneOf<Integer, String> chat_id, Optional<String> description = std::nullopt);

    Boolean PinChatMessage(OneOf<Integer, String> chat_id, Integer message_id,
                           Optional<String> business_connection_id = std::nullopt,
                           Optional<Boolean> disable_notification = std::nullopt);

    Boolean UnpinChatMessage(OneOf<Integer, String> chat_id, Optional<String> business_connection_id = std::nullopt,
                             Optional<Integer> message_id = std::nullopt);

    Boolean UnpinAllChatMessages(OneOf<Integer, String> chat_id);

    Boolean LeaveChat(OneOf<Integer, String> chat_id);

    ChatFullInfo GetChat(OneOf<Integer, String> chat_id);

    Array<ChatMember> GetChatAdministrators(OneOf<Integer, String> chat_id);

    Integer GetChatMemberCount(OneOf<Integer, String> chat_id);

    ChatMember GetChatMember(OneOf<Integer, String> chat_id, Integer user_id);

    Boolean SetChatStickerSet(OneOf<Integer, String> chat_id, String sticker_set_name);

    Boolean DeleteChatStickerSet(OneOf<Integer, String> chat_id);

    UserChatBoosts GetUserChatBoosts(OneOf<Integer, String> chat_id, Integer user_id);

    Boolean SetMyDefaultAdministratorRights(Optional<ChatAdministratorRights> rights = std::nullopt,
                                            Optional<Boolean> for_channels = std::nullopt);

    ChatAdministratorRights GetMyDefaultAdministratorRights(Optional<Boolean> for_channels = std::nullopt);

    Boolean VerifyChat(OneOf<Integer, String> chat_id, Optional<String> custom_description = std::nullopt);

    Boolean RemoveChatVerification(OneOf<Integer, String> chat_id);

    OwnedGifts GetChatGifts(OneOf<Integer, String> chat_id, Optional<Boolean> exclude_unsaved = std::nullopt,
                            Optional<Boolean> exclude_saved = std::nullopt,
                            Optional<Boolean> exclude_unlimited = std::nullopt,
                            Optional<Boolean> exclude_limited_upgradable = std::nullopt,
                            Optional<Boolean> exclude_limited_non_upgradable = std::nullopt,
                            Optional<Boolean> exclude_from_blockchain = std::nullopt,
                            Optional<Boolean> exclude_unique = std::nullopt,
                            Optional<Boolean> sort_by_price = std::nullopt, Optional<String> offset = std::nullopt,
                            Optional<Integer> limit = std::nullopt);

    Boolean ApproveSuggestedPost(Integer chat_id, Integer message_id, Optional<Integer> send_date = std::nullopt);

    Boolean DeclineSuggestedPost(Integer chat_id, Integer message_id, Optional<String> comment = std::nullopt);

    // Forum
    Array<Sticker> GetForumTopicIconStickers();

    ForumTopic CreateForumTopic(OneOf<Integer, String> chat_id, String name,
                                Optional<Integer> icon_color = std::nullopt,
                                Optional<String> icon_custom_emoji_id = std::nullopt);

    Boolean EditForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id,
                           Optional<String> name = std::nullopt, Optional<String> icon_custom_emoji_id = std::nullopt);

    Boolean CloseForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id);

    Boolean ReopenForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id);

    Boolean DeleteForumTopic(OneOf<Integer, String> chat_id, Integer message_thread_id);

    Boolean UnpinAllForumTopicMessages(OneOf<Integer, String> chat_id, Integer message_thread_id);

    Boolean EditGeneralForumTopic(OneOf<Integer, String> chat_id, String name);

    Boolean CloseGeneralForumTopic(OneOf<Integer, String> chat_id);

    Boolean ReopenGeneralForumTopic(OneOf<Integer, String> chat_id);

    Boolean HideGeneralForumTopic(OneOf<Integer, String> chat_id);

    Boolean UnhideGeneralForumTopic(OneOf<Integer, String> chat_id);

    Boolean UnpinAllGeneralForumTopicMessages(OneOf<Integer, String> chat_id);

    // Callback
    Boolean AnswerCallbackQuery(String callback_query_id, Optional<String> text = std::nullopt,
                                Optional<Boolean> show_alert = std::nullopt, Optional<String> url = std::nullopt,
                                Optional<Integer> cache_time = std::nullopt);

    // Gift
    Gifts GetAvailableGifts();

    Boolean SendGift(String gift_id, Optional<Integer> user_id = std::nullopt,
                     Optional<OneOf<Integer, String>> chat_id = std::nullopt,
                     Optional<Boolean> pay_for_upgrade = std::nullopt, Optional<String> text = std::nullopt,
                     Optional<String> text_parse_mode = std::nullopt,
                     Optional<Array<MessageEntity>> text_entities = std::nullopt);

    Boolean GiftPremiumSubscription(Integer user_id, Integer month_count, Integer star_count,
                                    Optional<String> text = std::nullopt,
                                    Optional<String> text_parse_mode = std::nullopt,
                                    Optional<Array<MessageEntity>> text_entities = std::nullopt);

    // Business
    Boolean ReadBusinessMessage(String business_connection_id, Integer chat_id, Integer message_id);

    Boolean DeleteBusinessMessages(String business_connection_id, Array<Integer> message_ids);

    Boolean SetBusinessAccountName(String business_connection_id, String first_name,
                                   Optional<String> last_name = std::nullopt);

    Boolean SetBusinessAccountUsername(String business_connection_id, Optional<String> username = std::nullopt);

    Boolean SetBusinessAccountBio(String business_connection_id, Optional<String> bio = std::nullopt);

    Boolean SetBusinessAccountProfilePhoto(String business_connection_id, InputProfilePhoto photo,
                                           Optional<Boolean> is_public = std::nullopt);

    Boolean RemoveBusinessAccountProfilePhoto(String business_connection_id,
                                              Optional<Boolean> is_public = std::nullopt);

    Boolean SetBusinessAccountGiftSettings(String business_connection_id, Boolean show_gift_button,
                                           AcceptedGiftTypes accepted_gift_types);

    StarAmount GetBusinessAccountStarBalance(String business_connection_id);

    Boolean TransferBusinessAccountStars(String business_connection_id, Integer star_count);

    OwnedGifts GetBusinessAccountGifts(String business_connection_id, Optional<Boolean> exclude_unsaved = std::nullopt,
                                       Optional<Boolean> exclude_saved = std::nullopt,
                                       Optional<Boolean> exclude_unlimited = std::nullopt,
                                       Optional<Boolean> exclude_limited_upgradable = std::nullopt,
                                       Optional<Boolean> exclude_limited_non_upgradable = std::nullopt,
                                       Optional<Boolean> exclude_unique = std::nullopt,
                                       Optional<Boolean> exclude_from_blockchain = std::nullopt,
                                       Optional<Boolean> sort_by_price = std::nullopt,
                                       Optional<String> offset = std::nullopt, Optional<Integer> limit = std::nullopt);

    Boolean ConvertGiftToStars(String business_connection_id, String owned_gift_id);

    Boolean UpgradeGift(String business_connection_id, String owned_gift_id,
                        Optional<Boolean> keep_original_details = std::nullopt,
                        Optional<Integer> star_count = std::nullopt);

    Boolean TransferGift(String business_connection_id, String owned_gift_id, Integer new_owner_chat_id,
                         Optional<Integer> star_count = std::nullopt);

    Story PostStory(String business_connection_id, InputStoryContent content, Integer active_period,
                    Optional<String> caption = std::nullopt, Optional<String> parse_mode = std::nullopt,
                    Optional<Array<MessageEntity>> caption_entities = std::nullopt,
                    Optional<Array<StoryArea>> areas = std::nullopt, Optional<Boolean> post_to_chat_page = std::nullopt,
                    Optional<Boolean> protect_content = std::nullopt);

    Story RepostStory(String business_connection_id, Integer from_chat_id, Integer from_story_id, Integer active_period,
                      Optional<Boolean> post_to_chat_page = std::nullopt,
                      Optional<Boolean> protect_content = std::nullopt);

    Story EditStory(String business_connection_id, Integer story_id, InputStoryContent content,
                    Optional<String> caption = std::nullopt, Optional<String> parse_mode = std::nullopt,
                    Optional<Array<MessageEntity>> caption_entities = std::nullopt,
                    Optional<Array<StoryArea>> areas = std::nullopt);

    Boolean DeleteStory(String business_connection_id, Integer story_id);

    // Inline
    Boolean AnswerInlineQuery(String inline_query_id, Array<InlineQueryResult> results,
                              Optional<Integer> cache_time = std::nullopt, Optional<Boolean> is_personal = std::nullopt,
                              Optional<String> next_offset = std::nullopt,
                              Optional<InlineQueryResultButton> button = std::nullopt);

    SentWebAppMessage AnswerWebAppQuery(String web_app_query_id, InlineQueryResult result);

    PreparedInlineMessage SavePreparedInlineMessage(Integer user_id, InlineQueryResult result,
                                                    Optional<Boolean> allow_user_chats = std::nullopt,
                                                    Optional<Boolean> allow_bot_chats = std::nullopt,
                                                    Optional<Boolean> allow_group_chats = std::nullopt,
                                                    Optional<Boolean> allow_channel_chats = std::nullopt);

    // Payment
    Message SendInvoice(
        OneOf<Integer, String> chat_id, String title, String description, String payload, String currency,
        Array<LabeledPrice> prices, Optional<Integer> message_thread_id = std::nullopt,
        Optional<Integer> direct_messages_topic_id = std::nullopt, Optional<String> provider_token = std::nullopt,
        Optional<Integer> max_tip_amount = std::nullopt, Optional<Array<Integer>> suggested_tip_amounts = std::nullopt,
        Optional<String> start_parameter = std::nullopt, Optional<String> provider_data = std::nullopt,
        Optional<String> photo_url = std::nullopt, Optional<Integer> photo_size = std::nullopt,
        Optional<Integer> photo_width = std::nullopt, Optional<Integer> photo_height = std::nullopt,
        Optional<Boolean> need_name = std::nullopt, Optional<Boolean> need_phone_number = std::nullopt,
        Optional<Boolean> need_email = std::nullopt, Optional<Boolean> need_shipping_address = std::nullopt,
        Optional<Boolean> send_phone_number_to_provider = std::nullopt,
        Optional<Boolean> send_email_to_provider = std::nullopt, Optional<Boolean> is_flexible = std::nullopt,
        Optional<Boolean> disable_notification = std::nullopt, Optional<Boolean> protect_content = std::nullopt,
        Optional<Boolean> allow_paid_broadcast = std::nullopt, Optional<String> message_effect_id = std::nullopt,
        Optional<SuggestedPostParameters> suggested_post_parameters = std::nullopt,
        Optional<ReplyParameters> reply_parameters = std::nullopt,
        Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    String CreateInvoiceLink(
        String title, String description, String payload, String currency, Array<LabeledPrice> prices,
        Optional<String> business_connection_id = std::nullopt, Optional<String> provider_token = std::nullopt,
        Optional<Integer> subscription_period = std::nullopt, Optional<Integer> max_tip_amount = std::nullopt,
        Optional<Array<Integer>> suggested_tip_amounts = std::nullopt, Optional<String> provider_data = std::nullopt,
        Optional<String> photo_url = std::nullopt, Optional<Integer> photo_size = std::nullopt,
        Optional<Integer> photo_width = std::nullopt, Optional<Integer> photo_height = std::nullopt,
        Optional<Boolean> need_name = std::nullopt, Optional<Boolean> need_phone_number = std::nullopt,
        Optional<Boolean> need_email = std::nullopt, Optional<Boolean> need_shipping_address = std::nullopt,
        Optional<Boolean> send_phone_number_to_provider = std::nullopt,
        Optional<Boolean> send_email_to_provider = std::nullopt, Optional<Boolean> is_flexible = std::nullopt);

    Boolean AnswerShippingQuery(String shipping_query_id, Boolean ok,
                                Optional<Array<ShippingOption>> shipping_options = std::nullopt,
                                Optional<String> error_message = std::nullopt);

    Boolean AnswerPreCheckoutQuery(String pre_checkout_query_id, Boolean ok,
                                   Optional<String> error_message = std::nullopt);

    StarAmount GetMyStarBalance();

    StarTransactions GetStarTransactions(Optional<Integer> offset = std::nullopt,
                                         Optional<Integer> limit = std::nullopt);

    Boolean RefundStarPayment(Integer user_id, String telegram_payment_charge_id);

    Boolean EditUserStarSubscription(Integer user_id, String telegram_payment_charge_id, Boolean is_canceled);

    // Passport
    Boolean SetPassportDataErrors(Integer user_id, Array<PassportElementError> errors);

    // Game
    Message SendGame(Integer chat_id, String game_short_name, Optional<String> business_connection_id = std::nullopt,
                     Optional<Integer> message_thread_id = std::nullopt,
                     Optional<Boolean> disable_notification = std::nullopt,
                     Optional<Boolean> protect_content = std::nullopt,
                     Optional<Boolean> allow_paid_broadcast = std::nullopt,
                     Optional<String> message_effect_id = std::nullopt,
                     Optional<ReplyParameters> reply_parameters = std::nullopt,
                     Optional<InlineKeyboardMarkup> reply_markup = std::nullopt);

    OneOf<Message, Boolean> SetGameScore(Integer user_id, Integer score, Optional<Boolean> force = std::nullopt,
                                         Optional<Boolean> disable_edit_message = std::nullopt,
                                         Optional<Integer> chat_id = std::nullopt,
                                         Optional<Integer> message_id = std::nullopt,
                                         Optional<String> inline_message_id = std::nullopt);

    Array<GameHighScore> GetGameHighScores(Integer user_id, Optional<Integer> chat_id = std::nullopt,
                                           Optional<Integer> message_id = std::nullopt,
                                           Optional<String> inline_message_id = std::nullopt);

   private:
    std::unique_ptr<internal::JsonClient> client;
    struct Timeouts {
        std::chrono::milliseconds common{2000};
        std::chrono::milliseconds webhook{5000};
        std::chrono::milliseconds long_poll_add{2000};
    };
    Timeouts timeouts;
};

}  // namespace tg
