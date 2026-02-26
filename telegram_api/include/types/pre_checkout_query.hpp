#pragma once

#include "common.hpp"
#include "order_info.hpp"
#include "user.hpp"

namespace tg {

struct PreCheckoutQuery {
    String id;
    User from;
    String currency;
    Integer total_amount;
    String invoice_payload;
    Optional<String> shipping_option_id;
    Optional<OrderInfo> order_info;
};

PreCheckoutQuery Parse(const Value& value, To<PreCheckoutQuery>);

}  // namespace tg
