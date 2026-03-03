#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/gift_background.hpp>
#include <tg/types/sticker.hpp>

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

void Serialize(const Gift& obj, ValueBuilder& builder);

}  // namespace tg
