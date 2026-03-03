#include <tg/types/chat_member_restricted.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChatMemberRestricted Parse(const Value& value, To<ChatMemberRestricted>) {
    ChatMemberRestricted obj{};
    obj.status = ParseComplex<String>(value["status"]);
    obj.tag = ParseComplex<Optional<String>>(value["tag"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.is_member = ParseComplex<Boolean>(value["is_member"]);
    obj.can_send_messages = ParseComplex<Boolean>(value["can_send_messages"]);
    obj.can_send_audios = ParseComplex<Boolean>(value["can_send_audios"]);
    obj.can_send_documents = ParseComplex<Boolean>(value["can_send_documents"]);
    obj.can_send_photos = ParseComplex<Boolean>(value["can_send_photos"]);
    obj.can_send_videos = ParseComplex<Boolean>(value["can_send_videos"]);
    obj.can_send_video_notes = ParseComplex<Boolean>(value["can_send_video_notes"]);
    obj.can_send_voice_notes = ParseComplex<Boolean>(value["can_send_voice_notes"]);
    obj.can_send_polls = ParseComplex<Boolean>(value["can_send_polls"]);
    obj.can_send_other_messages = ParseComplex<Boolean>(value["can_send_other_messages"]);
    obj.can_add_web_page_previews = ParseComplex<Boolean>(value["can_add_web_page_previews"]);
    obj.can_edit_tag = ParseComplex<Boolean>(value["can_edit_tag"]);
    obj.can_change_info = ParseComplex<Boolean>(value["can_change_info"]);
    obj.can_invite_users = ParseComplex<Boolean>(value["can_invite_users"]);
    obj.can_manage_topics = ParseComplex<Boolean>(value["can_manage_topics"]);
    obj.until_date = ParseComplex<Integer>(value["until_date"]);
    return obj;
}

void Serialize(const ChatMemberRestricted& obj, ValueBuilder& builder) {
    internal::Put(builder, "status", obj.status);
    internal::Put(builder, "tag", obj.tag);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "is_member", obj.is_member);
    internal::Put(builder, "can_send_messages", obj.can_send_messages);
    internal::Put(builder, "can_send_audios", obj.can_send_audios);
    internal::Put(builder, "can_send_documents", obj.can_send_documents);
    internal::Put(builder, "can_send_photos", obj.can_send_photos);
    internal::Put(builder, "can_send_videos", obj.can_send_videos);
    internal::Put(builder, "can_send_video_notes", obj.can_send_video_notes);
    internal::Put(builder, "can_send_voice_notes", obj.can_send_voice_notes);
    internal::Put(builder, "can_send_polls", obj.can_send_polls);
    internal::Put(builder, "can_send_other_messages", obj.can_send_other_messages);
    internal::Put(builder, "can_add_web_page_previews", obj.can_add_web_page_previews);
    internal::Put(builder, "can_edit_tag", obj.can_edit_tag);
    internal::Put(builder, "can_change_info", obj.can_change_info);
    internal::Put(builder, "can_invite_users", obj.can_invite_users);
    internal::Put(builder, "can_manage_topics", obj.can_manage_topics);
    internal::Put(builder, "until_date", obj.until_date);
}

}  // namespace tg
