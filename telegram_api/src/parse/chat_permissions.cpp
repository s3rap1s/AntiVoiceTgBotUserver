#include <types/chat_permissions.hpp>

#include "common.hpp"

namespace tg {

ChatPermissions Parse(const Value& value, To<ChatPermissions>) {
    ChatPermissions obj{};
    obj.can_send_messages =
        ParseComplex<Optional<Boolean>>(value["can_send_messages"]);
    obj.can_send_audios =
        ParseComplex<Optional<Boolean>>(value["can_send_audios"]);
    obj.can_send_documents =
        ParseComplex<Optional<Boolean>>(value["can_send_documents"]);
    obj.can_send_photos =
        ParseComplex<Optional<Boolean>>(value["can_send_photos"]);
    obj.can_send_videos =
        ParseComplex<Optional<Boolean>>(value["can_send_videos"]);
    obj.can_send_video_notes =
        ParseComplex<Optional<Boolean>>(value["can_send_video_notes"]);
    obj.can_send_voice_notes =
        ParseComplex<Optional<Boolean>>(value["can_send_voice_notes"]);
    obj.can_send_polls =
        ParseComplex<Optional<Boolean>>(value["can_send_polls"]);
    obj.can_send_other_messages =
        ParseComplex<Optional<Boolean>>(value["can_send_other_messages"]);
    obj.can_add_web_page_previews =
        ParseComplex<Optional<Boolean>>(value["can_add_web_page_previews"]);
    obj.can_edit_tag = ParseComplex<Optional<Boolean>>(value["can_edit_tag"]);
    obj.can_change_info =
        ParseComplex<Optional<Boolean>>(value["can_change_info"]);
    obj.can_invite_users =
        ParseComplex<Optional<Boolean>>(value["can_invite_users"]);
    obj.can_pin_messages =
        ParseComplex<Optional<Boolean>>(value["can_pin_messages"]);
    obj.can_manage_topics =
        ParseComplex<Optional<Boolean>>(value["can_manage_topics"]);
    return obj;
}

}  // namespace tg
