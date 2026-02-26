#pragma once

#include "common.hpp"

namespace tg {

struct TransactionPartnerTelegramApi {
    String type;
    Integer request_count;
};

TransactionPartnerTelegramApi Parse(const Value& value,
                                    To<TransactionPartnerTelegramApi>);

}  // namespace tg
