#pragma once

#include <userver/formats/json/value_builder.hpp>

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

void Serialize(const TransactionPartnerChat& obj, ValueBuilder& builder);

}  // namespace tg
