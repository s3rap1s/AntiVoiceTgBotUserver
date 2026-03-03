#include <tg/types/order_info.hpp>
#include <tg/types/pre_checkout_query.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PreCheckoutQuery Parse(const Value& value, To<PreCheckoutQuery>) {
    PreCheckoutQuery obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.total_amount = ParseComplex<Integer>(value["total_amount"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.shipping_option_id = ParseComplex<Optional<String>>(value["shipping_option_id"]);
    obj.order_info = ParseComplex<Optional<OrderInfo>>(value["order_info"]);
    return obj;
}

void Serialize(const PreCheckoutQuery& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "from", obj.from);
    internal::Put(builder, "currency", obj.currency);
    internal::Put(builder, "total_amount", obj.total_amount);
    internal::Put(builder, "invoice_payload", obj.invoice_payload);
    internal::Put(builder, "shipping_option_id", obj.shipping_option_id);
    internal::Put(builder, "order_info", obj.order_info);
}

}  // namespace tg
