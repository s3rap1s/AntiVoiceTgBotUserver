#include <tg/types/animation.hpp>
#include <tg/types/audio.hpp>
#include <tg/types/chat.hpp>
#include <tg/types/chat_background.hpp>
#include <tg/types/chat_boost_added.hpp>
#include <tg/types/chat_owner_changed.hpp>
#include <tg/types/chat_owner_left.hpp>
#include <tg/types/chat_shared.hpp>
#include <tg/types/checklist.hpp>
#include <tg/types/checklist_tasks_added.hpp>
#include <tg/types/checklist_tasks_done.hpp>
#include <tg/types/contact.hpp>
#include <tg/types/dice.hpp>
#include <tg/types/direct_message_price_changed.hpp>
#include <tg/types/direct_messages_topic.hpp>
#include <tg/types/document.hpp>
#include <tg/types/external_reply_info.hpp>
#include <tg/types/forum_topic_closed.hpp>
#include <tg/types/forum_topic_created.hpp>
#include <tg/types/forum_topic_edited.hpp>
#include <tg/types/forum_topic_reopened.hpp>
#include <tg/types/game.hpp>
#include <tg/types/general_forum_topic_hidden.hpp>
#include <tg/types/general_forum_topic_unhidden.hpp>
#include <tg/types/gift_info.hpp>
#include <tg/types/giveaway.hpp>
#include <tg/types/giveaway_completed.hpp>
#include <tg/types/giveaway_created.hpp>
#include <tg/types/giveaway_winners.hpp>
#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/invoice.hpp>
#include <tg/types/link_preview_options.hpp>
#include <tg/types/location.hpp>
#include <tg/types/maybe_inaccessible_message.hpp>
#include <tg/types/message.hpp>
#include <tg/types/message_auto_delete_timer_changed.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/message_origin.hpp>
#include <tg/types/paid_media_info.hpp>
#include <tg/types/paid_message_price_changed.hpp>
#include <tg/types/passport_data.hpp>
#include <tg/types/photo_size.hpp>
#include <tg/types/poll.hpp>
#include <tg/types/proximity_alert_triggered.hpp>
#include <tg/types/refunded_payment.hpp>
#include <tg/types/sticker.hpp>
#include <tg/types/story.hpp>
#include <tg/types/successful_payment.hpp>
#include <tg/types/suggested_post_approval_failed.hpp>
#include <tg/types/suggested_post_approved.hpp>
#include <tg/types/suggested_post_declined.hpp>
#include <tg/types/suggested_post_info.hpp>
#include <tg/types/suggested_post_paid.hpp>
#include <tg/types/suggested_post_refunded.hpp>
#include <tg/types/text_quote.hpp>
#include <tg/types/unique_gift_info.hpp>
#include <tg/types/user.hpp>
#include <tg/types/users_shared.hpp>
#include <tg/types/venue.hpp>
#include <tg/types/video.hpp>
#include <tg/types/video_chat_ended.hpp>
#include <tg/types/video_chat_participants_invited.hpp>
#include <tg/types/video_chat_scheduled.hpp>
#include <tg/types/video_chat_started.hpp>
#include <tg/types/video_note.hpp>
#include <tg/types/voice.hpp>
#include <tg/types/web_app_data.hpp>
#include <tg/types/write_access_allowed.hpp>

#include "common.hpp"

namespace tg {

Message Parse(const Value& value, To<Message>) {
    Message obj{};
    obj.message_id = ParseComplex<Integer>(value["message_id"]);
    obj.message_thread_id =
        ParseComplex<Optional<Integer>>(value["message_thread_id"]);
    obj.direct_messages_topic = ParseComplex<Optional<DirectMessagesTopic>>(
        value["direct_messages_topic"]);
    obj.from = ParseComplex<Optional<User>>(value["from"]);
    obj.sender_chat = ParseComplex<Optional<Chat>>(value["sender_chat"]);
    obj.sender_boost_count =
        ParseComplex<Optional<Integer>>(value["sender_boost_count"]);
    obj.sender_business_bot =
        ParseComplex<Optional<User>>(value["sender_business_bot"]);
    obj.sender_tag = ParseComplex<Optional<String>>(value["sender_tag"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.business_connection_id =
        ParseComplex<Optional<String>>(value["business_connection_id"]);
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.forward_origin =
        ParseComplex<Optional<MessageOrigin>>(value["forward_origin"]);
    obj.is_topic_message =
        ParseComplex<OptionalTrue>(value["is_topic_message"]);
    obj.is_automatic_forward =
        ParseComplex<OptionalTrue>(value["is_automatic_forward"]);
    obj.reply_to_message =
        ParseComplex<Ptr<Message>>(value["reply_to_message"]);
    obj.external_reply =
        ParseComplex<Optional<ExternalReplyInfo>>(value["external_reply"]);
    obj.quote = ParseComplex<Optional<TextQuote>>(value["quote"]);
    obj.reply_to_story = ParseComplex<Optional<Story>>(value["reply_to_story"]);
    obj.reply_to_checklist_task_id =
        ParseComplex<Optional<Integer>>(value["reply_to_checklist_task_id"]);
    obj.via_bot = ParseComplex<Optional<User>>(value["via_bot"]);
    obj.edit_date = ParseComplex<Optional<Integer>>(value["edit_date"]);
    obj.has_protected_content =
        ParseComplex<OptionalTrue>(value["has_protected_content"]);
    obj.is_from_offline = ParseComplex<OptionalTrue>(value["is_from_offline"]);
    obj.is_paid_post = ParseComplex<OptionalTrue>(value["is_paid_post"]);
    obj.media_group_id =
        ParseComplex<Optional<String>>(value["media_group_id"]);
    obj.author_signature =
        ParseComplex<Optional<String>>(value["author_signature"]);
    obj.paid_star_count =
        ParseComplex<Optional<Integer>>(value["paid_star_count"]);
    obj.text = ParseComplex<Optional<String>>(value["text"]);
    obj.entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["entities"]);
    obj.link_preview_options = ParseComplex<Optional<LinkPreviewOptions>>(
        value["link_preview_options"]);
    obj.suggested_post_info =
        ParseComplex<Optional<SuggestedPostInfo>>(value["suggested_post_info"]);
    obj.effect_id = ParseComplex<Optional<String>>(value["effect_id"]);
    obj.animation = ParseComplex<Optional<Animation>>(value["animation"]);
    obj.audio = ParseComplex<Optional<Audio>>(value["audio"]);
    obj.document = ParseComplex<Optional<Document>>(value["document"]);
    obj.paid_media = ParseComplex<Optional<PaidMediaInfo>>(value["paid_media"]);
    obj.photo = ParseComplex<Optional<Array<PhotoSize>>>(value["photo"]);
    obj.sticker = ParseComplex<Optional<Sticker>>(value["sticker"]);
    obj.story = ParseComplex<Optional<Story>>(value["story"]);
    obj.video = ParseComplex<Optional<Video>>(value["video"]);
    obj.video_note = ParseComplex<Optional<VideoNote>>(value["video_note"]);
    obj.voice = ParseComplex<Optional<Voice>>(value["voice"]);
    obj.caption = ParseComplex<Optional<String>>(value["caption"]);
    obj.caption_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["caption_entities"]);
    obj.show_caption_above_media =
        ParseComplex<OptionalTrue>(value["show_caption_above_media"]);
    obj.has_media_spoiler =
        ParseComplex<OptionalTrue>(value["has_media_spoiler"]);
    obj.checklist = ParseComplex<Optional<Checklist>>(value["checklist"]);
    obj.contact = ParseComplex<Optional<Contact>>(value["contact"]);
    obj.dice = ParseComplex<Optional<Dice>>(value["dice"]);
    obj.game = ParseComplex<Optional<Game>>(value["game"]);
    obj.poll = ParseComplex<Optional<Poll>>(value["poll"]);
    obj.venue = ParseComplex<Optional<Venue>>(value["venue"]);
    obj.location = ParseComplex<Optional<Location>>(value["location"]);
    obj.new_chat_members =
        ParseComplex<Optional<Array<User>>>(value["new_chat_members"]);
    obj.left_chat_member =
        ParseComplex<Optional<User>>(value["left_chat_member"]);
    obj.chat_owner_left =
        ParseComplex<Optional<ChatOwnerLeft>>(value["chat_owner_left"]);
    obj.chat_owner_changed =
        ParseComplex<Optional<ChatOwnerChanged>>(value["chat_owner_changed"]);
    obj.new_chat_title =
        ParseComplex<Optional<String>>(value["new_chat_title"]);
    obj.new_chat_photo =
        ParseComplex<Optional<Array<PhotoSize>>>(value["new_chat_photo"]);
    obj.delete_chat_photo =
        ParseComplex<OptionalTrue>(value["delete_chat_photo"]);
    obj.group_chat_created =
        ParseComplex<OptionalTrue>(value["group_chat_created"]);
    obj.supergroup_chat_created =
        ParseComplex<OptionalTrue>(value["supergroup_chat_created"]);
    obj.channel_chat_created =
        ParseComplex<OptionalTrue>(value["channel_chat_created"]);
    obj.message_auto_delete_timer_changed =
        ParseComplex<Optional<MessageAutoDeleteTimerChanged>>(
            value["message_auto_delete_timer_changed"]);
    obj.migrate_to_chat_id =
        ParseComplex<Optional<Integer>>(value["migrate_to_chat_id"]);
    obj.migrate_from_chat_id =
        ParseComplex<Optional<Integer>>(value["migrate_from_chat_id"]);
    obj.pinned_message = ParseComplex<Optional<MaybeInaccessibleMessage>>(
        value["pinned_message"]);
    obj.invoice = ParseComplex<Optional<Invoice>>(value["invoice"]);
    obj.successful_payment =
        ParseComplex<Optional<SuccessfulPayment>>(value["successful_payment"]);
    obj.refunded_payment =
        ParseComplex<Optional<RefundedPayment>>(value["refunded_payment"]);
    obj.users_shared =
        ParseComplex<Optional<UsersShared>>(value["users_shared"]);
    obj.chat_shared = ParseComplex<Optional<ChatShared>>(value["chat_shared"]);
    obj.gift = ParseComplex<Optional<GiftInfo>>(value["gift"]);
    obj.unique_gift =
        ParseComplex<Optional<UniqueGiftInfo>>(value["unique_gift"]);
    obj.gift_upgrade_sent =
        ParseComplex<Optional<GiftInfo>>(value["gift_upgrade_sent"]);
    obj.connected_website =
        ParseComplex<Optional<String>>(value["connected_website"]);
    obj.write_access_allowed = ParseComplex<Optional<WriteAccessAllowed>>(
        value["write_access_allowed"]);
    obj.passport_data =
        ParseComplex<Optional<PassportData>>(value["passport_data"]);
    obj.proximity_alert_triggered =
        ParseComplex<Optional<ProximityAlertTriggered>>(
            value["proximity_alert_triggered"]);
    obj.boost_added =
        ParseComplex<Optional<ChatBoostAdded>>(value["boost_added"]);
    obj.chat_background_set =
        ParseComplex<Optional<ChatBackground>>(value["chat_background_set"]);
    obj.checklist_tasks_done = ParseComplex<Optional<ChecklistTasksDone>>(
        value["checklist_tasks_done"]);
    obj.checklist_tasks_added = ParseComplex<Optional<ChecklistTasksAdded>>(
        value["checklist_tasks_added"]);
    obj.direct_message_price_changed =
        ParseComplex<Optional<DirectMessagePriceChanged>>(
            value["direct_message_price_changed"]);
    obj.forum_topic_created =
        ParseComplex<Optional<ForumTopicCreated>>(value["forum_topic_created"]);
    obj.forum_topic_edited =
        ParseComplex<Optional<ForumTopicEdited>>(value["forum_topic_edited"]);
    obj.forum_topic_closed =
        ParseComplex<Optional<ForumTopicClosed>>(value["forum_topic_closed"]);
    obj.forum_topic_reopened = ParseComplex<Optional<ForumTopicReopened>>(
        value["forum_topic_reopened"]);
    obj.general_forum_topic_unhidden =
        ParseComplex<Optional<GeneralForumTopicUnhidden>>(
            value["general_forum_topic_unhidden"]);
    obj.general_forum_topic_hidden =
        ParseComplex<Optional<GeneralForumTopicHidden>>(
            value["general_forum_topic_hidden"]);
    obj.giveaway_created =
        ParseComplex<Optional<GiveawayCreated>>(value["giveaway_created"]);
    obj.giveaway = ParseComplex<Optional<Giveaway>>(value["giveaway"]);
    obj.giveaway_winners =
        ParseComplex<Optional<GiveawayWinners>>(value["giveaway_winners"]);
    obj.giveaway_completed =
        ParseComplex<Optional<GiveawayCompleted>>(value["giveaway_completed"]);
    obj.paid_message_price_changed =
        ParseComplex<Optional<PaidMessagePriceChanged>>(
            value["paid_message_price_changed"]);
    obj.suggested_post_approved = ParseComplex<Optional<SuggestedPostApproved>>(
        value["suggested_post_approved"]);
    obj.suggested_post_approval_failed =
        ParseComplex<Optional<SuggestedPostApprovalFailed>>(
            value["suggested_post_approval_failed"]);
    obj.suggested_post_declined = ParseComplex<Optional<SuggestedPostDeclined>>(
        value["suggested_post_declined"]);
    obj.suggested_post_paid =
        ParseComplex<Optional<SuggestedPostPaid>>(value["suggested_post_paid"]);
    obj.suggested_post_refunded = ParseComplex<Optional<SuggestedPostRefunded>>(
        value["suggested_post_refunded"]);
    obj.video_chat_scheduled = ParseComplex<Optional<VideoChatScheduled>>(
        value["video_chat_scheduled"]);
    obj.video_chat_started =
        ParseComplex<Optional<VideoChatStarted>>(value["video_chat_started"]);
    obj.video_chat_ended =
        ParseComplex<Optional<VideoChatEnded>>(value["video_chat_ended"]);
    obj.video_chat_participants_invited =
        ParseComplex<Optional<VideoChatParticipantsInvited>>(
            value["video_chat_participants_invited"]);
    obj.web_app_data =
        ParseComplex<Optional<WebAppData>>(value["web_app_data"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    return obj;
}

}  // namespace tg
