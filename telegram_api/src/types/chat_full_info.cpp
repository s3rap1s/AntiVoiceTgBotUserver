#include <tg/types/accepted_gift_types.hpp>
#include <tg/types/audio.hpp>
#include <tg/types/birthdate.hpp>
#include <tg/types/business_intro.hpp>
#include <tg/types/business_location.hpp>
#include <tg/types/business_opening_hours.hpp>
#include <tg/types/chat.hpp>
#include <tg/types/chat_full_info.hpp>
#include <tg/types/chat_location.hpp>
#include <tg/types/chat_permissions.hpp>
#include <tg/types/chat_photo.hpp>
#include <tg/types/message.hpp>
#include <tg/types/reaction_type.hpp>
#include <tg/types/unique_gift_colors.hpp>
#include <tg/types/user_rating.hpp>

#include "../internal/json_builder.hpp"
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
    obj.is_direct_message = ParseComplex<OptionalTrue>(value["is_direct_message"]);
    obj.accent_color_id = ParseComplex<Integer>(value["accent_color_id"]);
    obj.max_reaction_count = ParseComplex<Integer>(value["max_reaction_count"]);
    obj.photo = ParseComplex<Optional<ChatPhoto>>(value["photo"]);
    obj.active_usernames = ParseComplex<Optional<Array<String>>>(value["active_usernames"]);
    obj.birthdate = ParseComplex<Optional<Birthdate>>(value["birthdate"]);
    obj.business_intro = ParseComplex<Optional<BusinessIntro>>(value["business_intro"]);
    obj.business_location = ParseComplex<Optional<BusinessLocation>>(value["business_location"]);
    obj.business_opening_hours = ParseComplex<Optional<BusinessOpeningHours>>(value["business_opening_hours"]);
    obj.personal_chat = ParseComplex<Optional<Chat>>(value["personal_chat"]);
    obj.parent_chat = ParseComplex<Optional<Chat>>(value["parent_chat"]);
    obj.available_reactions = ParseComplex<Optional<Array<ReactionType>>>(value["available_reactions"]);
    obj.background_custom_emoji_id = ParseComplex<Optional<String>>(value["background_custom_emoji_id"]);
    obj.profile_accent_color_id = ParseComplex<Optional<Integer>>(value["profile_accent_color_id"]);
    obj.profile_background_custom_emoji_id =
        ParseComplex<Optional<String>>(value["profile_background_custom_emoji_id"]);
    obj.emoji_status_custom_emoji_id = ParseComplex<Optional<String>>(value["emoji_status_custom_emoji_id"]);
    obj.emoji_status_expiration_date = ParseComplex<Optional<Integer>>(value["emoji_status_expiration_date"]);
    obj.bio = ParseComplex<Optional<String>>(value["bio"]);
    obj.has_private_forwards = ParseComplex<OptionalTrue>(value["has_private_forwards"]);
    obj.has_restricted_voice_and_video_messages =
        ParseComplex<OptionalTrue>(value["has_restricted_voice_and_video_messages"]);
    obj.join_to_send_messages = ParseComplex<OptionalTrue>(value["join_to_send_messages"]);
    obj.join_by_request = ParseComplex<OptionalTrue>(value["join_by_request"]);
    obj.description = ParseComplex<Optional<String>>(value["description"]);
    obj.invite_link = ParseComplex<Optional<String>>(value["invite_link"]);
    obj.pinned_message = ParseComplex<Ptr<Message>>(value["pinned_message"]);
    obj.permissions = ParseComplex<Optional<ChatPermissions>>(value["permissions"]);
    obj.accepted_gift_types = ParseComplex<Optional<AcceptedGiftTypes>>(value["accepted_gift_types"]);
    obj.can_send_paid_media = ParseComplex<OptionalTrue>(value["can_send_paid_media"]);
    obj.slow_mode_delay = ParseComplex<Optional<Integer>>(value["slow_mode_delay"]);
    obj.unrestrict_boost_count = ParseComplex<Optional<Integer>>(value["unrestrict_boost_count"]);
    obj.message_auto_delete_time = ParseComplex<Optional<Integer>>(value["message_auto_delete_time"]);
    obj.has_aggressive_anti_spam_enabled = ParseComplex<OptionalTrue>(value["has_aggressive_anti_spam_enabled"]);
    obj.has_hidden_members = ParseComplex<OptionalTrue>(value["has_hidden_members"]);
    obj.has_protected_content = ParseComplex<OptionalTrue>(value["has_protected_content"]);
    obj.has_visible_history = ParseComplex<OptionalTrue>(value["has_visible_history"]);
    obj.sticker_set_name = ParseComplex<Optional<String>>(value["sticker_set_name"]);
    obj.can_set_sticker_set = ParseComplex<OptionalTrue>(value["can_set_sticker_set"]);
    obj.custom_emoji_sticker_set_name = ParseComplex<Optional<String>>(value["custom_emoji_sticker_set_name"]);
    obj.linked_chat_id = ParseComplex<Optional<Integer>>(value["linked_chat_id"]);
    obj.location = ParseComplex<Optional<ChatLocation>>(value["location"]);
    obj.rating = ParseComplex<Optional<UserRating>>(value["rating"]);
    obj.first_profile_audio = ParseComplex<Optional<Audio>>(value["first_profile_audio"]);
    obj.unique_gift_colors = ParseComplex<Optional<UniqueGiftColors>>(value["unique_gift_colors"]);
    obj.paid_message_star_content = ParseComplex<Optional<Integer>>(value["paid_message_star_content"]);
    return obj;
}

void Serialize(const ChatFullInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "username", obj.username);
    internal::Put(builder, "first_name", obj.first_name);
    internal::Put(builder, "last_name", obj.last_name);
    internal::Put(builder, "is_forum", obj.is_forum);
    internal::Put(builder, "is_direct_message", obj.is_direct_message);
    internal::Put(builder, "accent_color_id", obj.accent_color_id);
    internal::Put(builder, "max_reaction_count", obj.max_reaction_count);
    internal::Put(builder, "photo", obj.photo);
    internal::Put(builder, "active_usernames", obj.active_usernames);
    internal::Put(builder, "birthdate", obj.birthdate);
    internal::Put(builder, "business_intro", obj.business_intro);
    internal::Put(builder, "business_location", obj.business_location);
    internal::Put(builder, "business_opening_hours", obj.business_opening_hours);
    internal::Put(builder, "personal_chat", obj.personal_chat);
    internal::Put(builder, "parent_chat", obj.parent_chat);
    internal::Put(builder, "available_reactions", obj.available_reactions);
    internal::Put(builder, "background_custom_emoji_id", obj.background_custom_emoji_id);
    internal::Put(builder, "profile_accent_color_id", obj.profile_accent_color_id);
    internal::Put(builder, "profile_background_custom_emoji_id", obj.profile_background_custom_emoji_id);
    internal::Put(builder, "emoji_status_custom_emoji_id", obj.emoji_status_custom_emoji_id);
    internal::Put(builder, "emoji_status_expiration_date", obj.emoji_status_expiration_date);
    internal::Put(builder, "bio", obj.bio);
    internal::Put(builder, "has_private_forwards", obj.has_private_forwards);
    internal::Put(builder, "has_restricted_voice_and_video_messages", obj.has_restricted_voice_and_video_messages);
    internal::Put(builder, "join_to_send_messages", obj.join_to_send_messages);
    internal::Put(builder, "join_by_request", obj.join_by_request);
    internal::Put(builder, "description", obj.description);
    internal::Put(builder, "invite_link", obj.invite_link);
    internal::Put(builder, "pinned_message", obj.pinned_message);
    internal::Put(builder, "permissions", obj.permissions);
    internal::Put(builder, "accepted_gift_types", obj.accepted_gift_types);
    internal::Put(builder, "can_send_paid_media", obj.can_send_paid_media);
    internal::Put(builder, "slow_mode_delay", obj.slow_mode_delay);
    internal::Put(builder, "unrestrict_boost_count", obj.unrestrict_boost_count);
    internal::Put(builder, "message_auto_delete_time", obj.message_auto_delete_time);
    internal::Put(builder, "has_aggressive_anti_spam_enabled", obj.has_aggressive_anti_spam_enabled);
    internal::Put(builder, "has_hidden_members", obj.has_hidden_members);
    internal::Put(builder, "has_protected_content", obj.has_protected_content);
    internal::Put(builder, "has_visible_history", obj.has_visible_history);
    internal::Put(builder, "sticker_set_name", obj.sticker_set_name);
    internal::Put(builder, "can_set_sticker_set", obj.can_set_sticker_set);
    internal::Put(builder, "custom_emoji_sticker_set_name", obj.custom_emoji_sticker_set_name);
    internal::Put(builder, "linked_chat_id", obj.linked_chat_id);
    internal::Put(builder, "location", obj.location);
    internal::Put(builder, "rating", obj.rating);
    internal::Put(builder, "first_profile_audio", obj.first_profile_audio);
    internal::Put(builder, "unique_gift_colors", obj.unique_gift_colors);
    internal::Put(builder, "paid_message_star_content", obj.paid_message_star_content);
}

}  // namespace tg
