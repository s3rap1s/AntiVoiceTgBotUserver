#include <types/chat.hpp>
#include <types/gift.hpp>
#include <types/gift_background.hpp>
#include <types/sticker.hpp>

#include "common.hpp"

namespace tg {

Gift Parse(const Value& value, To<Gift>) {
    Gift obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.sticker = ParseComplex<Sticker>(value["sticker"]);
    obj.star_count = ParseComplex<Integer>(value["star_count"]);
    obj.upgrade_star_count =
        ParseComplex<Optional<Integer>>(value["upgrade_star_count"]);
    obj.is_premium = ParseComplex<OptionalTrue>(value["is_premium"]);
    obj.has_colors = ParseComplex<OptionalTrue>(value["has_colors"]);
    obj.total_count = ParseComplex<Optional<Integer>>(value["total_count"]);
    obj.remaining_count =
        ParseComplex<Optional<Integer>>(value["remaining_count"]);
    obj.personal_total_count =
        ParseComplex<Optional<Integer>>(value["personal_total_count"]);
    obj.personal_remaining_count =
        ParseComplex<Optional<Integer>>(value["personal_remaining_count"]);
    obj.background =
        ParseComplex<Optional<GiftBackground>>(value["background"]);
    obj.unique_gift_variant_count =
        ParseComplex<Optional<Integer>>(value["unique_gift_variant_count"]);
    obj.publisher_chat = ParseComplex<Optional<Chat>>(value["publisher_chat"]);
    return obj;
}

}  // namespace tg
