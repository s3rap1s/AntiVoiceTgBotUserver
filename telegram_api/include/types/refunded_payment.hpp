#pragma once

#include "common.hpp"

namespace tg {

struct RefundedPayment {
    String currency;
    Integer total_amount;
    String invoice_payload;
    String telegram_payment_charge_id;
    Optional<String> provider_payment_charge_id;
};

RefundedPayment Parse(const Value& value, To<RefundedPayment>);

}  // namespace tg
