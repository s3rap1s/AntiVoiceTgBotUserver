#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/order_info.hpp>
#include <tg/types/user.hpp>

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

void Serialize(const PreCheckoutQuery& obj, ValueBuilder& builder);

}  // namespace tg
