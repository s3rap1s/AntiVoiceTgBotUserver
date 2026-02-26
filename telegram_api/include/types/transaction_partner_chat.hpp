#pragma once

#include "chat.hpp"
#include "common.hpp"
#include "gift.hpp"

namespace tg {

struct TransactionPartnerChat {
    String type;
    Chat chat;
    Optional<Gift> gift;
};

TransactionPartnerChat Parse(const Value& value, To<TransactionPartnerChat>);

}  // namespace tg
