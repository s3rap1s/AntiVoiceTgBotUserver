#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct ChatMemberRestricted {
    String status;
    Optional<String> tag;
    User user;
    Boolean is_member;
    Boolean can_send_messages;
    Boolean can_send_audios;
    Boolean can_send_documents;
    Boolean can_send_photos;
    Boolean can_send_videos;
    Boolean can_send_video_notes;
    Boolean can_send_voice_notes;
    Boolean can_send_polls;
    Boolean can_send_other_messages;
    Boolean can_add_web_page_previews;
    Boolean can_edit_tag;
    Boolean can_change_info;
    Boolean can_invite_users;
    Boolean can_manage_topics;
    Integer until_date;
};

ChatMemberRestricted Parse(const Value& value, To<ChatMemberRestricted>);

void Serialize(const ChatMemberRestricted& obj, ValueBuilder& builder);

}  // namespace tg
