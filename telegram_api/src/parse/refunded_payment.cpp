#include <tg/types/refunded_payment.hpp>

#include "common.hpp"

namespace tg {

RefundedPayment Parse(const Value& value, To<RefundedPayment>) {
    RefundedPayment obj{};
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.total_amount = ParseComplex<Integer>(value["total_amount"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.telegram_payment_charge_id =
        ParseComplex<String>(value["telegram_payment_charge_id"]);
    obj.provider_payment_charge_id =
        ParseComplex<Optional<String>>(value["provider_payment_charge_id"]);
    return obj;
}

}  // namespace tg
