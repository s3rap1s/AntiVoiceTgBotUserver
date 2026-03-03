#include <tg/types/chat.hpp>
#include <tg/types/gift.hpp>
#include <tg/types/gift_background.hpp>
#include <tg/types/sticker.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Gift Parse(const Value& value, To<Gift>) {
    Gift obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.sticker = ParseComplex<Sticker>(value["sticker"]);
    obj.star_count = ParseComplex<Integer>(value["star_count"]);
    obj.upgrade_star_count = ParseComplex<Optional<Integer>>(value["upgrade_star_count"]);
    obj.is_premium = ParseComplex<OptionalTrue>(value["is_premium"]);
    obj.has_colors = ParseComplex<OptionalTrue>(value["has_colors"]);
    obj.total_count = ParseComplex<Optional<Integer>>(value["total_count"]);
    obj.remaining_count = ParseComplex<Optional<Integer>>(value["remaining_count"]);
    obj.personal_total_count = ParseComplex<Optional<Integer>>(value["personal_total_count"]);
    obj.personal_remaining_count = ParseComplex<Optional<Integer>>(value["personal_remaining_count"]);
    obj.background = ParseComplex<Optional<GiftBackground>>(value["background"]);
    obj.unique_gift_variant_count = ParseComplex<Optional<Integer>>(value["unique_gift_variant_count"]);
    obj.publisher_chat = ParseComplex<Optional<Chat>>(value["publisher_chat"]);
    return obj;
}

void Serialize(const Gift& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "sticker", obj.sticker);
    internal::Put(builder, "star_count", obj.star_count);
    internal::Put(builder, "upgrade_star_count", obj.upgrade_star_count);
    internal::Put(builder, "is_premium", obj.is_premium);
    internal::Put(builder, "has_colors", obj.has_colors);
    internal::Put(builder, "total_count", obj.total_count);
    internal::Put(builder, "remaining_count", obj.remaining_count);
    internal::Put(builder, "personal_total_count", obj.personal_total_count);
    internal::Put(builder, "personal_remaining_count", obj.personal_remaining_count);
    internal::Put(builder, "background", obj.background);
    internal::Put(builder, "unique_gift_variant_count", obj.unique_gift_variant_count);
    internal::Put(builder, "publisher_chat", obj.publisher_chat);
}

}  // namespace tg
