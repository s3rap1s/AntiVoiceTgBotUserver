#include <types/accepted_gift_types.hpp>
#include <types/audio.hpp>
#include <types/birthdate.hpp>
#include <types/business_intro.hpp>
#include <types/business_location.hpp>
#include <types/business_opening_hours.hpp>
#include <types/chat.hpp>
#include <types/chat_full_info.hpp>
#include <types/chat_location.hpp>
#include <types/chat_permissions.hpp>
#include <types/chat_photo.hpp>
#include <types/message.hpp>
#include <types/reaction_type.hpp>
#include <types/unique_gift_colors.hpp>
#include <types/user_rating.hpp>

#include "common.hpp"

namespace tg {

ChatFullInfo Parse(const Value& value, To<ChatFullInfo>) {
    ChatFullInfo obj{};
    obj.id = ParseComplex<Integer>(value["id"]);
    obj.type = ParseComplex<String>(value["type"]);
    obj.title = ParseComplex<Optional<String>>(value["title"]);
    obj.username = ParseComplex<Optional<String>>(value["username"]);
    obj.first_name = ParseComplex<Optional<String>>(value["first_name"]);
    obj.last_name = ParseComplex<Optional<String>>(value["last_name"]);
    obj.is_forum = ParseComplex<OptionalTrue>(value["is_forum"]);
    obj.is_direct_message =
        ParseComplex<OptionalTrue>(value["is_direct_message"]);
    obj.accent_color_id = ParseComplex<Integer>(value["accent_color_id"]);
    obj.max_reaction_count = ParseComplex<Integer>(value["max_reaction_count"]);
    obj.photo = ParseComplex<Optional<ChatPhoto>>(value["photo"]);
    obj.active_usernames =
        ParseComplex<Optional<Array<String>>>(value["active_usernames"]);
    obj.birthdate = ParseComplex<Optional<Birthdate>>(value["birthdate"]);
    obj.business_intro =
        ParseComplex<Optional<BusinessIntro>>(value["business_intro"]);
    obj.business_location =
        ParseComplex<Optional<BusinessLocation>>(value["business_location"]);
    obj.business_opening_hours = ParseComplex<Optional<BusinessOpeningHours>>(
        value["business_opening_hours"]);
    obj.personal_chat = ParseComplex<Optional<Chat>>(value["personal_chat"]);
    obj.parent_chat = ParseComplex<Optional<Chat>>(value["parent_chat"]);
    obj.available_reactions = ParseComplex<Optional<Array<ReactionType>>>(
        value["available_reactions"]);
    obj.background_custom_emoji_id =
        ParseComplex<Optional<String>>(value["background_custom_emoji_id"]);
    obj.profile_accent_color_id =
        ParseComplex<Optional<Integer>>(value["profile_accent_color_id"]);
    obj.profile_background_custom_emoji_id = ParseComplex<Optional<String>>(
        value["profile_background_custom_emoji_id"]);
    obj.emoji_status_custom_emoji_id =
        ParseComplex<Optional<String>>(value["emoji_status_custom_emoji_id"]);
    obj.emoji_status_expiration_date =
        ParseComplex<Optional<Integer>>(value["emoji_status_expiration_date"]);
    obj.bio = ParseComplex<Optional<String>>(value["bio"]);
    obj.has_private_forwards =
        ParseComplex<OptionalTrue>(value["has_private_forwards"]);
    obj.has_restricted_voice_and_video_messages = ParseComplex<OptionalTrue>(
        value["has_restricted_voice_and_video_messages"]);
    obj.join_to_send_messages =
        ParseComplex<OptionalTrue>(value["join_to_send_messages"]);
    obj.join_by_request = ParseComplex<OptionalTrue>(value["join_by_request"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.invite_link = ParseComplex<Optional<String>>(value["invite_link"]);
    obj.pinned_message = ParseComplex<Ptr<Message>>(value["pinned_message"]);
    obj.permissions =
        ParseComplex<Optional<ChatPermissions>>(value["permissions"]);
    obj.accepted_gift_types =
        ParseComplex<Optional<AcceptedGiftTypes>>(value["accepted_gift_types"]);
    obj.can_send_paid_media =
        ParseComplex<OptionalTrue>(value["can_send_paid_media"]);
    obj.slow_mode_delay =
        ParseComplex<Optional<Integer>>(value["slow_mode_delay"]);
    obj.unrestrict_boost_count =
        ParseComplex<Optional<Integer>>(value["unrestrict_boost_count"]);
    obj.message_auto_delete_time =
        ParseComplex<Optional<Integer>>(value["message_auto_delete_time"]);
    obj.has_aggressive_anti_spam_enabled =
        ParseComplex<OptionalTrue>(value["has_aggressive_anti_spam_enabled"]);
    obj.has_hidden_members =
        ParseComplex<OptionalTrue>(value["has_hidden_members"]);
    obj.has_protected_content =
        ParseComplex<OptionalTrue>(value["has_protected_content"]);
    obj.has_visible_history =
        ParseComplex<OptionalTrue>(value["has_visible_history"]);
    obj.sticker_set_name =
        ParseComplex<Optional<String>>(value["sticker_set_name"]);
    obj.can_set_sticker_set =
        ParseComplex<OptionalTrue>(value["can_set_sticker_set"]);
    obj.custom_emoji_sticker_set_name =
        ParseComplex<Optional<String>>(value["custom_emoji_sticker_set_name"]);
    obj.linked_chat_id =
        ParseComplex<Optional<Integer>>(value["linked_chat_id"]);
    obj.location = ParseComplex<Optional<ChatLocation>>(value["location"]);
    obj.rating = ParseComplex<Optional<UserRating>>(value["rating"]);
    obj.first_profile_audio =
        ParseComplex<Optional<Audio>>(value["first_profile_audio"]);
    obj.unique_gift_colors =
        ParseComplex<Optional<UniqueGiftColors>>(value["unique_gift_colors"]);
    obj.paid_message_star_content =
        ParseComplex<Optional<Integer>>(value["paid_message_star_content"]);
    return obj;
}

}  // namespace tg
