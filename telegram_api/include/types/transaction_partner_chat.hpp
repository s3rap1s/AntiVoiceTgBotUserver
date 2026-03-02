#pragma once

#include <types/chat.hpp>
#include <types/common.hpp>
#include <types/gift.hpp>

namespace tg {

struct TransactionPartnerChat {
    String type;
    Chat chat;
    Optional<Gift> gift;
};

TransactionPartnerChat Parse(const Value& value, To<TransactionPartnerChat>);

}  // namespace tg
