#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>
#include <types/gift_background.hpp>
#include <types/sticker.hpp>

namespace tg {

struct Gift {
    String id;
    Sticker sticker;
    Integer star_count;
    Optional<Integer> upgrade_star_count;
    OptionalTrue is_premium;
    OptionalTrue has_colors;
    Optional<Integer> total_count;
    Optional<Integer> remaining_count;
    Optional<Integer> personal_total_count;
    Optional<Integer> personal_remaining_count;
    Optional<GiftBackground> background;
    Optional<Integer> unique_gift_variant_count;
    Optional<Chat> publisher_chat;
};

Gift Parse(const Value& value, To<Gift>);

}  // namespace tg
