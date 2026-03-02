#include <types/order_info.hpp>
#include <types/pre_checkout_query.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

PreCheckoutQuery Parse(const Value& value, To<PreCheckoutQuery>) {
    PreCheckoutQuery obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.total_amount = ParseComplex<Integer>(value["total_amount"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.shipping_option_id =
        ParseComplex<Optional<String>>(value["shipping_option_id"]);
    obj.order_info = ParseComplex<Optional<OrderInfo>>(value["order_info"]);
    return obj;
}

}  // namespace tg
