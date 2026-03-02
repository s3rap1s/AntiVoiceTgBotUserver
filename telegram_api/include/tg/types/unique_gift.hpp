#pragma once

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/unique_gift_backdrop.hpp>
#include <tg/types/unique_gift_colors.hpp>
#include <tg/types/unique_gift_model.hpp>
#include <tg/types/unique_gift_symbol.hpp>

namespace tg {

struct UniqueGift {
    String gift_id;
    String base_name;
    String name;
    Integer number;
    UniqueGiftModel model;
    UniqueGiftSymbol symbol;
    UniqueGiftBackdrop backdrop;
    OptionalTrue is_premium;
    OptionalTrue is_burned;
    OptionalTrue is_from_blockchain;
    UniqueGiftColors colors;
    Optional<Chat> publisher_chat;
};

UniqueGift Parse(const Value& value, To<UniqueGift>);

}  // namespace tg
