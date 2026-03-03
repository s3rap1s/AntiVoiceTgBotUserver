#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

UserProfilePhotos BotApi::GetUserProfilePhotos(Integer user_id, Optional<Integer> offset, Optional<Integer> limit) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "offset", offset);
    internal::Put(builder, "limit", limit);

    const auto result = client->CallResult("getUserProfilePhotos", builder.ExtractValue(), timeouts.common);

    return result.As<UserProfilePhotos>();
}

UserProfileAudios BotApi::GetUserProfileAudios(Integer user_id, Optional<Integer> offset, Optional<Integer> limit) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "offset", offset);
    internal::Put(builder, "limit", limit);

    const auto result = client->CallResult("getUserProfileAudios", builder.ExtractValue(), timeouts.common);

    return result.As<UserProfileAudios>();
}

Boolean BotApi::SetUserEmojiStatus(Integer user_id, Optional<String> emoji_status_custom_emoji_id,
                                   Optional<Integer> emoji_status_expiration_date) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "emoji_status_custom_emoji_id", emoji_status_custom_emoji_id);
    internal::Put(builder, "emoji_status_expiration_date", emoji_status_expiration_date);

    const auto result = client->CallResult("setUserEmojiStatus", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::VerifyUser(Integer user_id, Optional<String> custom_description) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "custom_description", custom_description);

    const auto result = client->CallResult("verifyUser", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::RemoveUserVerification(Integer user_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);

    const auto result = client->CallResult("removeUserVerification", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

OwnedGifts BotApi::GetUserGifts(Integer user_id, Optional<Boolean> exclude_unlimited,
                                Optional<Boolean> exclude_limited_upgradable,
                                Optional<Boolean> exclude_limited_non_upgradable,
                                Optional<Boolean> exclude_from_blockchain, Optional<Boolean> exclude_unique,
                                Optional<Boolean> sort_by_price, Optional<String> offset, Optional<Integer> limit) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "exclude_unlimited", exclude_unlimited);
    internal::Put(builder, "exclude_limited_upgradable", exclude_limited_upgradable);
    internal::Put(builder, "exclude_limited_non_upgradable", exclude_limited_non_upgradable);
    internal::Put(builder, "exclude_from_blockchain", exclude_from_blockchain);
    internal::Put(builder, "exclude_unique", exclude_unique);
    internal::Put(builder, "sort_by_price", sort_by_price);
    internal::Put(builder, "offset", offset);
    internal::Put(builder, "limit", limit);

    const auto result = client->CallResult("getUserGifts", builder.ExtractValue(), timeouts.common);

    return result.As<OwnedGifts>();
}

}  // namespace tg
