#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct TransactionPartnerOther {
    String type;
};

TransactionPartnerOther Parse(const Value& value, To<TransactionPartnerOther>);

void Serialize(const TransactionPartnerOther& obj, ValueBuilder& builder);

}  // namespace tg
