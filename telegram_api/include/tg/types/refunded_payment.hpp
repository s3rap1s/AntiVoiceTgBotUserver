#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct RefundedPayment {
    String currency;
    Integer total_amount;
    String invoice_payload;
    String telegram_payment_charge_id;
    Optional<String> provider_payment_charge_id;
};

RefundedPayment Parse(const Value& value, To<RefundedPayment>);

void Serialize(const RefundedPayment& obj, ValueBuilder& builder);

}  // namespace tg
