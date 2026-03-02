#pragma once

#include <types/common.hpp>
#include <types/order_info.hpp>
#include <types/user.hpp>

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
