#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct TransactionPartnerTelegramApi {
    String type;
    Integer request_count;
};

TransactionPartnerTelegramApi Parse(const Value& value, To<TransactionPartnerTelegramApi>);

void Serialize(const TransactionPartnerTelegramApi& obj, ValueBuilder& builder);

}  // namespace tg
