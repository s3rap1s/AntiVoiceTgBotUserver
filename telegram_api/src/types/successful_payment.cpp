#include <tg/types/order_info.hpp>
#include <tg/types/successful_payment.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

SuccessfulPayment Parse(const Value& value, To<SuccessfulPayment>) {
    SuccessfulPayment obj{};
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.total_amount = ParseComplex<Integer>(value["total_amount"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.subscription_expiration_date = ParseComplex<Optional<Integer>>(value["subscription_expiration_date"]);
    obj.is_recurring = ParseComplex<OptionalTrue>(value["is_recurring"]);
    obj.is_first_recurring = ParseComplex<OptionalTrue>(value["is_first_recurring"]);
    obj.shipping_option_id = ParseComplex<Optional<String>>(value["shipping_option_id"]);
    obj.order_info = ParseComplex<Optional<OrderInfo>>(value["order_info"]);
    obj.telegram_payment_charge_id = ParseComplex<String>(value["telegram_payment_charge_id"]);
    obj.provider_payment_charge_id = ParseComplex<String>(value["provider_payment_charge_id"]);
    return obj;
}

void Serialize(const SuccessfulPayment& obj, ValueBuilder& builder) {
    internal::Put(builder, "currency", obj.currency);
    internal::Put(builder, "total_amount", obj.total_amount);
    internal::Put(builder, "invoice_payload", obj.invoice_payload);
    internal::Put(builder, "subscription_expiration_date", obj.subscription_expiration_date);
    internal::Put(builder, "is_recurring", obj.is_recurring);
    internal::Put(builder, "is_first_recurring", obj.is_first_recurring);
    internal::Put(builder, "shipping_option_id", obj.shipping_option_id);
    internal::Put(builder, "order_info", obj.order_info);
    internal::Put(builder, "telegram_payment_charge_id", obj.telegram_payment_charge_id);
    internal::Put(builder, "provider_payment_charge_id", obj.provider_payment_charge_id);
}

}  // namespace tg
