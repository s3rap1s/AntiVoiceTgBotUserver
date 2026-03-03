#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BusinessBotRights {
    OptionalTrue can_reply;
    OptionalTrue can_read_messages;
    OptionalTrue can_delete_sent_messages;
    OptionalTrue can_delete_all_messages;
    OptionalTrue can_edit_name;
    OptionalTrue can_edit_bio;
    OptionalTrue can_edit_profile_photo;
    OptionalTrue can_edit_username;
    OptionalTrue can_change_gift_settings;
    OptionalTrue can_view_gifts_and_stars;
    OptionalTrue can_convert_gifts_to_stars;
    OptionalTrue can_transfer_and_upgrade_gifts;
    OptionalTrue can_transfer_stars;
    OptionalTrue can_manage_stories;
};

BusinessBotRights Parse(const Value& value, To<BusinessBotRights>);

void Serialize(const BusinessBotRights& obj, ValueBuilder& builder);

}  // namespace tg
