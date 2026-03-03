#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Boolean BotApi::SetMessageReaction(OneOf<Integer, String> chat_id, Integer message_id,
                                   Optional<Array<ReactionType>> reaction, Optional<Boolean> is_big) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "reaction", reaction);
    internal::Put(builder, "is_big", is_big);

    const auto result = client->CallResult("setMessageReaction", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::BanChatMember(OneOf<Integer, String> chat_id, Integer user_id, Optional<Integer> until_date,
                              Optional<Boolean> revoke_messages) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "until_date", until_date);
    internal::Put(builder, "revoke_messages", revoke_messages);

    const auto result = client->CallResult("banChatMember", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UnbanChatMember(OneOf<Integer, String> chat_id, Integer user_id, Optional<Boolean> only_if_banned) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "only_if_banned", only_if_banned);

    const auto result = client->CallResult("unbanChatMember", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::RestrictChatMember(OneOf<Integer, String> chat_id, Integer user_id, ChatPermissions permissions,
                                   Optional<Boolean> use_independent_chat_permissions, Optional<Integer> until_date) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "permissions", permissions);
    internal::Put(builder, "use_independent_chat_permissions", use_independent_chat_permissions);
    internal::Put(builder, "until_date", until_date);

    const auto result = client->CallResult("restrictChatMember", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::PromoteChatMember(OneOf<Integer, String> chat_id, Integer user_id, Optional<Boolean> is_anonymous,
                                  Optional<Boolean> can_manage_chat, Optional<Boolean> can_delete_messages,
                                  Optional<Boolean> can_manage_video_chats, Optional<Boolean> can_restrict_members,
                                  Optional<Boolean> can_promote_members, Optional<Boolean> can_change_info,
                                  Optional<Boolean> can_invite_users, Optional<Boolean> can_post_stories,
                                  Optional<Boolean> can_edit_stories, Optional<Boolean> can_delete_stories,
                                  Optional<Boolean> can_post_messages, Optional<Boolean> can_edit_messages,
                                  Optional<Boolean> can_pin_messages, Optional<Boolean> can_manage_topics,
                                  Optional<Boolean> can_manage_direct_messages, Optional<Boolean> can_manage_tags) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "is_anonymous", is_anonymous);
    internal::Put(builder, "can_manage_chat", can_manage_chat);
    internal::Put(builder, "can_delete_messages", can_delete_messages);
    internal::Put(builder, "can_manage_video_chats", can_manage_video_chats);
    internal::Put(builder, "can_restrict_members", can_restrict_members);
    internal::Put(builder, "can_promote_members", can_promote_members);
    internal::Put(builder, "can_change_info", can_change_info);
    internal::Put(builder, "can_invite_users", can_invite_users);
    internal::Put(builder, "can_post_stories", can_post_stories);
    internal::Put(builder, "can_edit_stories", can_edit_stories);
    internal::Put(builder, "can_delete_stories", can_delete_stories);
    internal::Put(builder, "can_post_messages", can_post_messages);
    internal::Put(builder, "can_edit_messages", can_edit_messages);
    internal::Put(builder, "can_pin_messages", can_pin_messages);
    internal::Put(builder, "can_manage_topics", can_manage_topics);
    internal::Put(builder, "can_manage_direct_messages", can_manage_direct_messages);
    internal::Put(builder, "can_manage_tags", can_manage_tags);

    const auto result = client->CallResult("promoteChatMember", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetChatAdministratorCustomTitle(OneOf<Integer, String> chat_id, Integer user_id, String custom_title) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "custom_title", custom_title);

    const auto result = client->CallResult("setChatAdministratorCustomTitle", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetChatMemberTag(OneOf<Integer, String> chat_id, Integer user_id, Optional<String> tag) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "tag", tag);

    const auto result = client->CallResult("setChatMemberTag", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::BanChatSenderChat(OneOf<Integer, String> chat_id, Integer sender_chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "sender_chat_id", sender_chat_id);

    const auto result = client->CallResult("banChatSenderChat", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UnbanChatSenderChat(OneOf<Integer, String> chat_id, Integer sender_chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "sender_chat_id", sender_chat_id);

    const auto result = client->CallResult("unbanChatSenderChat", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetChatPermissions(OneOf<Integer, String> chat_id, ChatPermissions permissions,
                                   Optional<Boolean> use_independent_chat_permissions) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "permissions", permissions);
    internal::Put(builder, "use_independent_chat_permissions", use_independent_chat_permissions);

    const auto result = client->CallResult("setChatPermissions", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

String BotApi::ExportChatInviteLink(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("exportChatInviteLink", builder.ExtractValue(), timeouts.common);

    return result.As<String>();
}

ChatInviteLink BotApi::CreateChatInviteLink(OneOf<Integer, String> chat_id, Optional<String> name,
                                            Optional<Integer> expire_date, Optional<Integer> member_limit,
                                            Optional<Boolean> creates_join_request) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "name", name);
    internal::Put(builder, "expire_date", expire_date);
    internal::Put(builder, "member_limit", member_limit);
    internal::Put(builder, "creates_join_request", creates_join_request);

    const auto result = client->CallResult("createChatInviteLink", builder.ExtractValue(), timeouts.common);

    return result.As<ChatInviteLink>();
}

ChatInviteLink BotApi::EditChatInviteLink(OneOf<Integer, String> chat_id, String invite_link, Optional<String> name,
                                          Optional<Integer> expire_date, Optional<Integer> member_limit,
                                          Optional<Boolean> creates_join_request) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "invite_link", invite_link);
    internal::Put(builder, "name", name);
    internal::Put(builder, "expire_date", expire_date);
    internal::Put(builder, "member_limit", member_limit);
    internal::Put(builder, "creates_join_request", creates_join_request);

    const auto result = client->CallResult("editChatInviteLink", builder.ExtractValue(), timeouts.common);

    return result.As<ChatInviteLink>();
}

ChatInviteLink BotApi::CreateChatSubscriptionInviteLink(OneOf<Integer, String> chat_id, Integer subscription_period,
                                                        Integer subscription_price, Optional<String> name) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "subscription_period", subscription_period);
    internal::Put(builder, "subscription_price", subscription_price);
    internal::Put(builder, "name", name);

    const auto result = client->CallResult("createChatSubscriptionInviteLink", builder.ExtractValue(), timeouts.common);

    return result.As<ChatInviteLink>();
}

ChatInviteLink BotApi::EditChatSubscriptionInviteLink(OneOf<Integer, String> chat_id, String invite_link,
                                                      Optional<String> name) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "invite_link", invite_link);
    internal::Put(builder, "name", name);

    const auto result = client->CallResult("editChatSubscriptionInviteLink", builder.ExtractValue(), timeouts.common);

    return result.As<ChatInviteLink>();
}

ChatInviteLink BotApi::RevokeChatInviteLink(OneOf<Integer, String> chat_id, String invite_link) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "invite_link", invite_link);

    const auto result = client->CallResult("revokeChatInviteLink", builder.ExtractValue(), timeouts.common);

    return result.As<ChatInviteLink>();
}

Boolean BotApi::ApproveChatJoinRequest(OneOf<Integer, String> chat_id, Integer user_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);

    const auto result = client->CallResult("approveChatJoinRequest", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeclineChatJoinRequest(OneOf<Integer, String> chat_id, Integer user_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);

    const auto result = client->CallResult("declineChatJoinRequest", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetChatPhoto(OneOf<Integer, String> chat_id, InputFile photo) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "photo", photo);

    const auto result = client->CallResult("setChatPhoto", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteChatPhoto(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("deleteChatPhoto", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetChatTitle(OneOf<Integer, String> chat_id, String title) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "title", title);

    const auto result = client->CallResult("setChatTitle", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetChatDescription(OneOf<Integer, String> chat_id, Optional<String> description) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "description", description);

    const auto result = client->CallResult("setChatDescription", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::PinChatMessage(OneOf<Integer, String> chat_id, Integer message_id,
                               Optional<String> business_connection_id, Optional<Boolean> disable_notification) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "disable_notification", disable_notification);

    const auto result = client->CallResult("pinChatMessage", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UnpinChatMessage(OneOf<Integer, String> chat_id, Optional<String> business_connection_id,
                                 Optional<Integer> message_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_id", message_id);

    const auto result = client->CallResult("unpinChatMessage", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UnpinAllChatMessages(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("unpinAllChatMessages", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::LeaveChat(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("leaveChat", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

ChatFullInfo BotApi::GetChat(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("getChat", builder.ExtractValue(), timeouts.common);

    return result.As<ChatFullInfo>();
}

Array<ChatMember> BotApi::GetChatAdministrators(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("getChatAdministrators", builder.ExtractValue(), timeouts.common);

    Array<ChatMember> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<ChatMember>());
    }
    return out;
}

Integer BotApi::GetChatMemberCount(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("getChatMemberCount", builder.ExtractValue(), timeouts.common);

    return result.As<Integer>();
}

ChatMember BotApi::GetChatMember(OneOf<Integer, String> chat_id, Integer user_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);

    const auto result = client->CallResult("getChatMember", builder.ExtractValue(), timeouts.common);

    return result.As<ChatMember>();
}

Boolean BotApi::SetChatStickerSet(OneOf<Integer, String> chat_id, String sticker_set_name) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "sticker_set_name", sticker_set_name);

    const auto result = client->CallResult("setChatStickerSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteChatStickerSet(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("deleteChatStickerSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

UserChatBoosts BotApi::GetUserChatBoosts(OneOf<Integer, String> chat_id, Integer user_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "user_id", user_id);

    const auto result = client->CallResult("getUserChatBoosts", builder.ExtractValue(), timeouts.common);

    return result.As<UserChatBoosts>();
}

Boolean BotApi::SetMyDefaultAdministratorRights(Optional<ChatAdministratorRights> rights,
                                                Optional<Boolean> for_channels) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "rights", rights);
    internal::Put(builder, "for_channels", for_channels);

    const auto result = client->CallResult("setMyDefaultAdministratorRights", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

ChatAdministratorRights BotApi::GetMyDefaultAdministratorRights(Optional<Boolean> for_channels) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "for_channels", for_channels);

    const auto result = client->CallResult("getMyDefaultAdministratorRights", builder.ExtractValue(), timeouts.common);

    return result.As<ChatAdministratorRights>();
}

Boolean BotApi::VerifyChat(OneOf<Integer, String> chat_id, Optional<String> custom_description) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "custom_description", custom_description);

    const auto result = client->CallResult("verifyChat", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::RemoveChatVerification(OneOf<Integer, String> chat_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);

    const auto result = client->CallResult("removeChatVerification", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

OwnedGifts BotApi::GetChatGifts(OneOf<Integer, String> chat_id, Optional<Boolean> exclude_unsaved,
                                Optional<Boolean> exclude_saved, Optional<Boolean> exclude_unlimited,
                                Optional<Boolean> exclude_limited_upgradable,
                                Optional<Boolean> exclude_limited_non_upgradable,
                                Optional<Boolean> exclude_from_blockchain, Optional<Boolean> exclude_unique,
                                Optional<Boolean> sort_by_price, Optional<String> offset, Optional<Integer> limit) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "exclude_unsaved", exclude_unsaved);
    internal::Put(builder, "exclude_saved", exclude_saved);
    internal::Put(builder, "exclude_unlimited", exclude_unlimited);
    internal::Put(builder, "exclude_limited_upgradable", exclude_limited_upgradable);
    internal::Put(builder, "exclude_limited_non_upgradable", exclude_limited_non_upgradable);
    internal::Put(builder, "exclude_from_blockchain", exclude_from_blockchain);
    internal::Put(builder, "exclude_unique", exclude_unique);
    internal::Put(builder, "sort_by_price", sort_by_price);
    internal::Put(builder, "offset", offset);
    internal::Put(builder, "limit", limit);

    const auto result = client->CallResult("getChatGifts", builder.ExtractValue(), timeouts.common);

    return result.As<OwnedGifts>();
}

Boolean BotApi::ApproveSuggestedPost(Integer chat_id, Integer message_id, Optional<Integer> send_date) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "send_date", send_date);

    const auto result = client->CallResult("approveSuggestedPost", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeclineSuggestedPost(Integer chat_id, Integer message_id, Optional<String> comment) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);
    internal::Put(builder, "comment", comment);

    const auto result = client->CallResult("declineSuggestedPost", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
