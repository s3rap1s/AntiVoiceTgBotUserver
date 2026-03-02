#include <types/order_info.hpp>
#include <types/successful_payment.hpp>

#include "common.hpp"

namespace tg {

SuccessfulPayment Parse(const Value& value, To<SuccessfulPayment>) {
    SuccessfulPayment obj{};
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.total_amount = ParseComplex<Integer>(value["total_amount"]);
    obj.invoice_payload = ParseComplex<String>(value["invoice_payload"]);
    obj.subscription_expiration_date =
        ParseComplex<Optional<Integer>>(value["subscription_expiration_date"]);
    obj.is_recurring = ParseComplex<OptionalTrue>(value["is_recurring"]);
    obj.is_first_recurring =
        ParseComplex<OptionalTrue>(value["is_first_recurring"]);
    obj.shipping_option_id =
        ParseComplex<Optional<String>>(value["shipping_option_id"]);
    obj.order_info = ParseComplex<Optional<OrderInfo>>(value["order_info"]);
    obj.telegram_payment_charge_id =
        ParseComplex<String>(value["telegram_payment_charge_id"]);
    obj.provider_payment_charge_id =
        ParseComplex<String>(value["provider_payment_charge_id"]);
    return obj;
}

}  // namespace tg
