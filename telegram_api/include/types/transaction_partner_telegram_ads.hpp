#pragma once

#include "common.hpp"

namespace tg {

struct TransactionPartnerTelegramAds {
    String type;
};

TransactionPartnerTelegramAds Parse(const Value& value,
                                    To<TransactionPartnerTelegramAds>);

}  // namespace tg
