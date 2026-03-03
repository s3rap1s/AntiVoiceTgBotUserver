#include <tg/types/business_bot_rights.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BusinessBotRights Parse(const Value& value, To<BusinessBotRights>) {
    BusinessBotRights obj{};
    obj.can_reply = ParseComplex<OptionalTrue>(value["can_reply"]);
    obj.can_read_messages = ParseComplex<OptionalTrue>(value["can_read_messages"]);
    obj.can_delete_sent_messages = ParseComplex<OptionalTrue>(value["can_delete_sent_messages"]);
    obj.can_delete_all_messages = ParseComplex<OptionalTrue>(value["can_delete_all_messages"]);
    obj.can_edit_name = ParseComplex<OptionalTrue>(value["can_edit_name"]);
    obj.can_edit_bio = ParseComplex<OptionalTrue>(value["can_edit_bio"]);
    obj.can_edit_profile_photo = ParseComplex<OptionalTrue>(value["can_edit_profile_photo"]);
    obj.can_edit_username = ParseComplex<OptionalTrue>(value["can_edit_username"]);
    obj.can_change_gift_settings = ParseComplex<OptionalTrue>(value["can_change_gift_settings"]);
    obj.can_view_gifts_and_stars = ParseComplex<OptionalTrue>(value["can_view_gifts_and_stars"]);
    obj.can_convert_gifts_to_stars = ParseComplex<OptionalTrue>(value["can_convert_gifts_to_stars"]);
    obj.can_transfer_and_upgrade_gifts = ParseComplex<OptionalTrue>(value["can_transfer_and_upgrade_gifts"]);
    obj.can_transfer_stars = ParseComplex<OptionalTrue>(value["can_transfer_stars"]);
    obj.can_manage_stories = ParseComplex<OptionalTrue>(value["can_manage_stories"]);
    return obj;
}

void Serialize(const BusinessBotRights& obj, ValueBuilder& builder) {
    internal::Put(builder, "can_reply", obj.can_reply);
    internal::Put(builder, "can_read_messages", obj.can_read_messages);
    internal::Put(builder, "can_delete_sent_messages", obj.can_delete_sent_messages);
    internal::Put(builder, "can_delete_all_messages", obj.can_delete_all_messages);
    internal::Put(builder, "can_edit_name", obj.can_edit_name);
    internal::Put(builder, "can_edit_bio", obj.can_edit_bio);
    internal::Put(builder, "can_edit_profile_photo", obj.can_edit_profile_photo);
    internal::Put(builder, "can_edit_username", obj.can_edit_username);
    internal::Put(builder, "can_change_gift_settings", obj.can_change_gift_settings);
    internal::Put(builder, "can_view_gifts_and_stars", obj.can_view_gifts_and_stars);
    internal::Put(builder, "can_convert_gifts_to_stars", obj.can_convert_gifts_to_stars);
    internal::Put(builder, "can_transfer_and_upgrade_gifts", obj.can_transfer_and_upgrade_gifts);
    internal::Put(builder, "can_transfer_stars", obj.can_transfer_stars);
    internal::Put(builder, "can_manage_stories", obj.can_manage_stories);
}

}  // namespace tg
