#include <tg/types/input_invoice_message_content.hpp>
#include <tg/types/labeled_price.hpp>

#include "common.hpp"

namespace tg {

InputInvoiceMessageContent Parse(const Value& value,
                                 To<InputInvoiceMessageContent>) {
    InputInvoiceMessageContent obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.description = ParseComplex<String>(value["description"]);
    obj.payload = ParseComplex<String>(value["payload"]);
    obj.provider_token =
        ParseComplex<Optional<String>>(value["provider_token"]);
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.prices = ParseComplex<Optional<Array<LabeledPrice>>>(value["prices"]);
    obj.max_tip_amount =
        ParseComplex<Optional<Integer>>(value["max_tip_amount"]);
    obj.suggested_tip_amounts =
        ParseComplex<Optional<Array<Integer>>>(value["suggested_tip_amounts"]);
    obj.provider_data = ParseComplex<Optional<String>>(value["provider_data"]);
    obj.photo_url = ParseComplex<Optional<String>>(value["photo_url"]);
    obj.photo_size = ParseComplex<Optional<Boolean>>(value["photo_size"]);
    obj.photo_width = ParseComplex<Optional<Integer>>(value["photo_width"]);
    obj.photo_height = ParseComplex<Optional<Integer>>(value["photo_height"]);
    obj.need_name = ParseComplex<Optional<Boolean>>(value["need_name"]);
    obj.need_phone_number =
        ParseComplex<Optional<Boolean>>(value["need_phone_number"]);
    obj.need_email = ParseComplex<Optional<Boolean>>(value["need_email"]);
    obj.need_shipping_address =
        ParseComplex<Optional<Boolean>>(value["need_shipping_address"]);
    obj.send_phone_number_to_provider =
        ParseComplex<Optional<Boolean>>(value["send_phone_number_to_provider"]);
    obj.send_email_to_provider =
        ParseComplex<Optional<Boolean>>(value["send_email_to_provider"]);
    obj.is_flexible = ParseComplex<Optional<Boolean>>(value["is_flexible"]);
    return obj;
}

}  // namespace tg
