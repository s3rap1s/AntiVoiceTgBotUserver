#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct TransactionPartnerTelegramApi {
    String type;
    Integer request_count;
};

TransactionPartnerTelegramApi Parse(const Value& value,
                                    To<TransactionPartnerTelegramApi>);

}  // namespace tg
