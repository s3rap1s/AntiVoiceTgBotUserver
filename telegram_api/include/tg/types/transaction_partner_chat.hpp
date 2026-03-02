#pragma once

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/gift.hpp>

namespace tg {

struct TransactionPartnerChat {
    String type;
    Chat chat;
    Optional<Gift> gift;
};

TransactionPartnerChat Parse(const Value& value, To<TransactionPartnerChat>);

}  // namespace tg
