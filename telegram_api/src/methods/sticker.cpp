#include <tg/bot_api.hpp>

#include "../internal/json_builder.hpp"
#include "../internal/json_client.hpp"

namespace tg {

Message BotApi::SendSticker(
    OneOf<Integer, String> chat_id, OneOf<InputFile, String> sticker, Optional<String> business_connection_id,
    Optional<Integer> message_thread_id, Optional<Integer> direct_messages_topic_id, Optional<String> emoji,
    Optional<Boolean> disable_notification, Optional<Boolean> protect_content, Optional<Boolean> allow_paid_broadcast,
    Optional<String> message_effect_id, Optional<SuggestedPostParameters> suggested_post_parameters,
    Optional<ReplyParameters> reply_parameters,
    Optional<OneOf<InlineKeyboardMarkup, ReplyKeyboardMarkup, ReplyKeyboardRemove, ForceReply>> reply_markup) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "chat_id", chat_id);
    internal::Put(builder, "sticker", sticker);
    internal::Put(builder, "business_connection_id", business_connection_id);
    internal::Put(builder, "message_thread_id", message_thread_id);
    internal::Put(builder, "direct_messages_topic_id", direct_messages_topic_id);
    internal::Put(builder, "emoji", emoji);
    internal::Put(builder, "disable_notification", disable_notification);
    internal::Put(builder, "protect_content", protect_content);
    internal::Put(builder, "allow_paid_broadcast", allow_paid_broadcast);
    internal::Put(builder, "message_effect_id", message_effect_id);
    internal::Put(builder, "suggested_post_parameters", suggested_post_parameters);
    internal::Put(builder, "reply_parameters", reply_parameters);
    internal::Put(builder, "reply_markup", reply_markup);

    const auto result = client->CallResult("sendSticker", builder.ExtractValue(), timeouts.common);

    return result.As<Message>();
}

StickerSet BotApi::GetStickerSet(String name) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "name", name);

    const auto result = client->CallResult("getStickerSet", builder.ExtractValue(), timeouts.common);

    return result.As<StickerSet>();
}

Array<Sticker> BotApi::GetCustomEmojiStickers(Array<String> custom_emoji_ids) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "custom_emoji_ids", custom_emoji_ids);

    const auto result = client->CallResult("getCustomEmojiStickers", builder.ExtractValue(), timeouts.common);

    Array<Sticker> out;
    out.reserve(result.GetSize());
    for (const auto& item : result) {
        out.push_back(item.As<Sticker>());
    }
    return out;
}

File BotApi::UploadStickerFile(Integer user_id, InputFile sticker, String sticker_format) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "sticker", sticker);
    internal::Put(builder, "sticker_format", sticker_format);

    const auto result = client->CallResult("uploadStickerFile", builder.ExtractValue(), timeouts.common);

    return result.As<File>();
}

Boolean BotApi::CreateNewStickerSet(Integer user_id, String name, String title, Array<InputSticker> stickers,
                                    Optional<String> sticker_type, Optional<Boolean> needs_repainting) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "name", name);
    internal::Put(builder, "title", title);
    internal::Put(builder, "stickers", stickers);
    internal::Put(builder, "sticker_type", sticker_type);
    internal::Put(builder, "needs_repainting", needs_repainting);

    const auto result = client->CallResult("createNewStickerSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::AddStickerToSet(Integer user_id, String name, InputSticker sticker) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "name", name);
    internal::Put(builder, "sticker", sticker);

    const auto result = client->CallResult("addStickerToSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetStickerPositionInSet(String sticker, Integer position) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "sticker", sticker);
    internal::Put(builder, "position", position);

    const auto result = client->CallResult("setStickerPositionInSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteStickerFromSet(String sticker) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "sticker", sticker);

    const auto result = client->CallResult("deleteStickerFromSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::ReplaceStickerInSet(Integer user_id, String name, String old_sticker, InputSticker sticker) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "name", name);
    internal::Put(builder, "old_sticker", old_sticker);
    internal::Put(builder, "sticker", sticker);

    const auto result = client->CallResult("replaceStickerInSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetStickerEmojiList(String sticker, Array<String> emoji_list) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "sticker", sticker);
    internal::Put(builder, "emoji_list", emoji_list);

    const auto result = client->CallResult("setStickerEmojiList", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetStickerKeywords(String sticker, Optional<Array<String>> keywords) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "sticker", sticker);
    internal::Put(builder, "keywords", keywords);

    const auto result = client->CallResult("setStickerKeywords", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetStickerMaskPosition(String sticker, Optional<MaskPosition> mask_position) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "sticker", sticker);
    internal::Put(builder, "mask_position", mask_position);

    const auto result = client->CallResult("setStickerMaskPosition", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetStickerSetTitle(String name, String title) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "name", name);
    internal::Put(builder, "title", title);

    const auto result = client->CallResult("setStickerSetTitle", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetStickerSetThumbnail(String name, Integer user_id, String format,
                                       Optional<OneOf<InputFile, String>> thumbnail) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "name", name);
    internal::Put(builder, "user_id", user_id);
    internal::Put(builder, "format", format);
    internal::Put(builder, "thumbnail", thumbnail);

    const auto result = client->CallResult("setStickerSetThumbnail", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::SetCustomEmojiStickerSetThumbnail(String name, Optional<String> custom_emoji_id) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "name", name);
    internal::Put(builder, "custom_emoji_id", custom_emoji_id);

    const auto result =
        client->CallResult("setCustomEmojiStickerSetThumbnail", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

Boolean BotApi::DeleteStickerSet(String name) {
    auto builder = internal::MakeObject();
    internal::Put(builder, "name", name);

    const auto result = client->CallResult("deleteStickerSet", builder.ExtractValue(), timeouts.common);

    return result.As<Boolean>();
}

}  // namespace tg
