#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Boolean BotApi::ReadBusinessMessage(String business_connection_id, Integer chat_id, Integer message_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "message_id", message_id);

    const auto result = client->CallResult("readBusinessMessage", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteBusinessMessages(String business_connection_id, Array<Integer> message_ids) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_ids", message_ids);

    const auto result = client->CallResult("deleteBusinessMessages", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetBusinessAccountName(String business_connection_id, String first_name, Optional<String> last_name) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "first_name", first_name);
    internal::Put(builder, "last_name", last_name);

    const auto result = client->CallResult("setBusinessAccountName", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetBusinessAccountUsername(String business_connection_id, Optional<String> username) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "username", username);

    const auto result = client->CallResult("setBusinessAccountUsername", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetBusinessAccountBio(String business_connection_id, Optional<String> bio) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "bio", bio);

    const auto result = client->CallResult("setBusinessAccountBio", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetBusinessAccountProfilePhoto(String business_connection_id, InputProfilePhoto photo,
                                               Optional<Boolean> is_public) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "photo", photo);
    internal::Put(builder, "is_public", is_public);

    const auto result = client->CallResult("setBusinessAccountProfilePhoto", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::RemoveBusinessAccountProfilePhoto(String business_connection_id, Optional<Boolean> is_public) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "is_public", is_public);

    const auto result =
        client->CallResult("removeBusinessAccountProfilePhoto", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetBusinessAccountGiftSettings(String business_connection_id, Boolean show_gift_button,
                                               AcceptedGiftTypes accepted_gift_types) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "show_gift_button", show_gift_button);
    internal::Put(builder, "accepted_gift_types", accepted_gift_types);

    const auto result = client->CallResult("setBusinessAccountGiftSettings", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

StarAmount BotApi::GetBusinessAccountStarBalance(String business_connection_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);

    const auto result = client->CallResult("getBusinessAccountStarBalance", builder.ExtractValue(), timeouts.common);

    return result.As<StarAmount>();
}

Boolean BotApi::TransferBusinessAccountStars(String business_connection_id, Integer star_count) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "star_count", star_count);

    const auto result = client->CallResult("transferBusinessAccountStars", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

OwnedGifts BotApi::GetBusinessAccountGifts(String business_connection_id, Optional<Boolean> exclude_unsaved,
                                           Optional<Boolean> exclude_saved, Optional<Boolean> exclude_unlimited,
                                           Optional<Boolean> exclude_limited_upgradable,
                                           Optional<Boolean> exclude_limited_non_upgradable,
                                           Optional<Boolean> exclude_unique, Optional<Boolean> exclude_from_blockchain,
                                           Optional<Boolean> sort_by_price, Optional<String> offset,
                                           Optional<Integer> limit) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "exclude_unsaved", exclude_unsaved);
    internal::Put(builder, "exclude_saved", exclude_saved);
    internal::Put(builder, "exclude_unlimited", exclude_unlimited);
    internal::Put(builder, "exclude_limited_upgradable", exclude_limited_upgradable);
    internal::Put(builder, "exclude_limited_non_upgradable", exclude_limited_non_upgradable);
    internal::Put(builder, "exclude_unique", exclude_unique);
    internal::Put(builder, "exclude_from_blockchain", exclude_from_blockchain);
    internal::Put(builder, "sort_by_price", sort_by_price);
    internal::Put(builder, "offset", offset);
    internal::Put(builder, "limit", limit);

    const auto result = client->CallResult("getBusinessAccountGifts", builder.ExtractValue(), timeouts.common);

    return result.As<OwnedGifts>();
}

Boolean BotApi::ConvertGiftToStars(String business_connection_id, String owned_gift_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "owned_gift_id", owned_gift_id);

    const auto result = client->CallResult("convertGiftToStars", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::UpgradeGift(String business_connection_id, String owned_gift_id,
                            Optional<Boolean> keep_original_details, Optional<Integer> star_count) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "owned_gift_id", owned_gift_id);
    internal::Put(builder, "keep_original_details", keep_original_details);
    internal::Put(builder, "star_count", star_count);

    const auto result = client->CallResult("upgradeGift", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::TransferGift(String business_connection_id, String owned_gift_id, Integer new_owner_chat_id,
                             Optional<Integer> star_count) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "owned_gift_id", owned_gift_id);
    internal::Put(builder, "new_owner_chat_id", new_owner_chat_id);
    internal::Put(builder, "star_count", star_count);

    const auto result = client->CallResult("transferGift", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Story BotApi::PostStory(String business_connection_id, InputStoryContent content, Integer active_period,
                        Optional<String> caption, Optional<String> parse_mode,
                        Optional<Array<MessageEntity>> caption_entities, Optional<Array<StoryArea>> areas,
                        Optional<Boolean> post_to_chat_page, Optional<Boolean> protect_content) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "content", content);
    internal::Put(builder, "active_period", active_period);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "areas", areas);
    internal::Put(builder, "post_to_chat_page", post_to_chat_page);
    internal::Put(builder, "protect_content", protect_content);

    const auto result = client->CallResult("postStory", builder.ExtractValue(), timeouts.common);

    return result.As<Story>();
}

Story BotApi::RepostStory(String business_connection_id, Integer from_chat_id, Integer from_story_id,
                          Integer active_period, Optional<Boolean> post_to_chat_page,
                          Optional<Boolean> protect_content) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "from_chat_id", from_chat_id);
    internal::Put(builder, "from_story_id", from_story_id);
    internal::Put(builder, "active_period", active_period);
    internal::Put(builder, "post_to_chat_page", post_to_chat_page);
    internal::Put(builder, "protect_content", protect_content);

    const auto result = client->CallResult("repostStory", builder.ExtractValue(), timeouts.common);

    return result.As<Story>();
}

Story BotApi::EditStory(String business_connection_id, Integer story_id, InputStoryContent content,
                        Optional<String> caption, Optional<String> parse_mode,
                        Optional<Array<MessageEntity>> caption_entities, Optional<Array<StoryArea>> areas) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "story_id", story_id);
    internal::Put(builder, "content", content);
    internal::Put(builder, "caption", caption);
    internal::Put(builder, "parse_mode", parse_mode);
    internal::Put(builder, "caption_entities", caption_entities);
    internal::Put(builder, "areas", areas);

    const auto result = client->CallResult("editStory", builder.ExtractValue(), timeouts.common);

    return result.As<Story>();
}

Boolean BotApi::DeleteStory(String business_connection_id, Integer story_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "story_id", story_id);

    const auto result = client->CallResult("deleteStory", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
