#include <tg/types/refunded_payment.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

RefundedPayment Parse(const Value& value, To<RefundedPayment>) {
    RefundedPayment obj{};
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.total_amount = ParseComplex<Integer>(value["total_amount"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.telegram_payment_charge_id = ParseComplex<String>(value["telegram_payment_charge_id"]);
    obj.provider_payment_charge_id = ParseComplex<Optional<String>>(value["provider_payment_charge_id"]);
    return obj;
}

void Serialize(const RefundedPayment& obj, ValueBuilder& builder) {
    internal::Put(builder, "currency", obj.currency);
    internal::Put(builder, "total_amount", obj.total_amount);
    internal::Put(builder, "invoice_payload", obj.invoice_payload);
    internal::Put(builder, "telegram_payment_charge_id", obj.telegram_payment_charge_id);
    internal::Put(builder, "provider_payment_charge_id", obj.provider_payment_charge_id);
}

}  // namespace tg
