#pragma once

#include "accepted_gift_types.hpp"
#include "birthdate.hpp"
#include "business_intro.hpp"
#include "business_location.hpp"
#include "business_opening_hours.hpp"
#include "chat.hpp"
#include "chat_location.hpp"
#include "chat_permissions.hpp"
#include "chat_photo.hpp"
#include "common.hpp"
#include "message.hpp"
#include "reaction_type.hpp"
#include "unique_gift_colors.hpp"
#include "user_rating.hpp"

namespace tg {

struct ChatFullInfo {
    Integer id;
    String type;
    Optional<String> title;
    Optional<String> username;
    Optional<String> first_name;
    Optional<String> last_name;
    OptionalTrue is_forum;
    OptionalTrue is_direct_message;
    Integer accent_color_id;
    Integer max_reaction_count;
    Optional<ChatPhoto> photo;
    Optional<Array<String>> active_usernames;
    Optional<Birthdate> birthdate;
    Optional<BusinessIntro> business_intro;
    Optional<BusinessLocation> business_location;
    Optional<BusinessOpeningHours> business_opening_hours;
    Optional<Chat> personal_chat;
    Optional<Chat> parent_chat;
    Optional<Array<ReactionType>> available_reactions;
    Optional<String> background_custom_emoji_id;
    Optional<Integer> profile_accent_color_id;
    Optional<String> profile_background_custom_emoji_id;
    Optional<String> emoji_status_custom_emoji_id;
    Optional<Integer> emoji_status_expiration_date;
    Optional<String> bio;
    OptionalTrue has_private_forwards;
    OptionalTrue has_restricted_voice_and_video_messages;
    OptionalTrue join_to_send_messages;
    OptionalTrue join_by_request;
    Optional<String> description;
    Optional<String> invite_link;
    Ptr<Message> pinned_message;
    Optional<ChatPermissions> persmissions;
    Optional<AcceptedGiftTypes> accepted_gift_types;
    OptionalTrue can_send_paid_media;
    Optional<Integer> slow_mode_delay;
    Optional<Integer> unrestrict_boost_count;
    Optional<Integer> message_auto_delete_time;
    OptionalTrue has_aggressive_anti_spam_enabled;
    OptionalTrue has_hidden_members;
    OptionalTrue has_protected_content;
    OptionalTrue has_visible_history;
    Optional<String> sticker_set_name;
    OptionalTrue can_set_sticker_set;
    Optional<String> custom_emoji_sticker_set_name;
    Optional<Integer> linked_chat_id;
    Optional<ChatLocation> location;
    Optional<UserRating> rating;
    Optional<Audio> first_profile_audio;
    Optional<UniqueGiftColors> unique_gift_colors;
    Optional<Integer> paid_message_star_content;
};

ChatFullInfo Parse(const Value& value, To<ChatFullInfo>);
}  // namespace tg
