#pragma once

#include <tg/types/common.hpp>
#include <tg/types/order_info.hpp>

namespace tg {

struct SuccessfulPayment {
    String currency;
    Integer total_amount;
    String invoice_payload;
    Optional<Integer> subscription_expiration_date;
    OptionalTrue is_recurring;
    OptionalTrue is_first_recurring;
    Optional<String> shipping_option_id;
    Optional<OrderInfo> order_info;
    String telegram_payment_charge_id;
    String provider_payment_charge_id;
};

SuccessfulPayment Parse(const Value& value, To<SuccessfulPayment>);

}  // namespace tg
