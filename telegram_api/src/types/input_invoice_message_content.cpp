#include <tg/types/input_invoice_message_content.hpp>
#include <tg/types/labeled_price.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputInvoiceMessageContent Parse(const Value& value, To<InputInvoiceMessageContent>) {
    InputInvoiceMessageContent obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.description = ParseComplex<String>(value["description"]);
    obj.payload = ParseComplex<String>(value["payload"]);
    obj.provider_token = ParseComplex<Optional<String>>(value["provider_token"]);
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.prices = ParseComplex<Optional<Array<LabeledPrice>>>(value["prices"]);
    obj.max_tip_amount = ParseComplex<Optional<Integer>>(value["max_tip_amount"]);
    obj.suggested_tip_amounts = ParseComplex<Optional<Array<Integer>>>(value["suggested_tip_amounts"]);
    obj.provider_data = ParseComplex<Optional<String>>(value["provider_data"]);
    obj.photo_url = ParseComplex<Optional<String>>(value["photo_url"]);
    obj.photo_size = ParseComplex<Optional<Boolean>>(value["photo_size"]);
    obj.photo_width = ParseComplex<Optional<Integer>>(value["photo_width"]);
    obj.photo_height = ParseComplex<Optional<Integer>>(value["photo_height"]);
    obj.need_name = ParseComplex<Optional<Boolean>>(value["need_name"]);
    obj.need_phone_number = ParseComplex<Optional<Boolean>>(value["need_phone_number"]);
    obj.need_email = ParseComplex<Optional<Boolean>>(value["need_email"]);
    obj.need_shipping_address = ParseComplex<Optional<Boolean>>(value["need_shipping_address"]);
    obj.send_phone_number_to_provider = ParseComplex<Optional<Boolean>>(value["send_phone_number_to_provider"]);
    obj.send_email_to_provider = ParseComplex<Optional<Boolean>>(value["send_email_to_provider"]);
    obj.is_flexible = ParseComplex<Optional<Boolean>>(value["is_flexible"]);
    return obj;
}

void Serialize(const InputInvoiceMessageContent& obj, ValueBuilder& builder) {
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "description", obj.description);
    internal::Put(builder, "payload", obj.payload);
    internal::Put(builder, "provider_token", obj.provider_token);
    internal::Put(builder, "currency", obj.currency);
    internal::Put(builder, "prices", obj.prices);
    internal::Put(builder, "max_tip_amount", obj.max_tip_amount);
    internal::Put(builder, "suggested_tip_amounts", obj.suggested_tip_amounts);
    internal::Put(builder, "provider_data", obj.provider_data);
    internal::Put(builder, "photo_url", obj.photo_url);
    internal::Put(builder, "photo_size", obj.photo_size);
    internal::Put(builder, "photo_width", obj.photo_width);
    internal::Put(builder, "photo_height", obj.photo_height);
    internal::Put(builder, "need_name", obj.need_name);
    internal::Put(builder, "need_phone_number", obj.need_phone_number);
    internal::Put(builder, "need_email", obj.need_email);
    internal::Put(builder, "need_shipping_address", obj.need_shipping_address);
    internal::Put(builder, "send_phone_number_to_provider", obj.send_phone_number_to_provider);
    internal::Put(builder, "send_email_to_provider", obj.send_email_to_provider);
    internal::Put(builder, "is_flexible", obj.is_flexible);
}

}  // namespace tg
