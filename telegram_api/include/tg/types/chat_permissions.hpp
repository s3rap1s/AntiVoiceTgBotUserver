#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct ChatPermissions {
    Optional<Boolean> can_send_messages;
    Optional<Boolean> can_send_audios;
    Optional<Boolean> can_send_documents;
    Optional<Boolean> can_send_photos;
    Optional<Boolean> can_send_videos;
    Optional<Boolean> can_send_video_notes;
    Optional<Boolean> can_send_voice_notes;
    Optional<Boolean> can_send_polls;
    Optional<Boolean> can_send_other_messages;
    Optional<Boolean> can_add_web_page_previews;
    Optional<Boolean> can_edit_tag;
    Optional<Boolean> can_change_info;
    Optional<Boolean> can_invite_users;
    Optional<Boolean> can_pin_messages;
    Optional<Boolean> can_manage_topics;
};

ChatPermissions Parse(const Value& value, To<ChatPermissions>);

}  // namespace tg
