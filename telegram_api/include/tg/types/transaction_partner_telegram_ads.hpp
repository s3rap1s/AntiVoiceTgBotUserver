#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct TransactionPartnerTelegramAds {
    String type;
};

TransactionPartnerTelegramAds Parse(const Value& value, To<TransactionPartnerTelegramAds>);

void Serialize(const TransactionPartnerTelegramAds& obj, ValueBuilder& builder);

}  // namespace tg
