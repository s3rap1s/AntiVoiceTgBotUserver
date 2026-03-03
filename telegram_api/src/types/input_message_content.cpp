#include <tg/types/input_contact_message_content.hpp>
#include <tg/types/input_invoice_message_content.hpp>
#include <tg/types/input_location_message_content.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/input_text_message_content.hpp>
#include <tg/types/input_venue_message_content.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputMessageContent Parse(const Value& value, To<InputMessageContent>) {
    if (internal::IsPresent(value["message_text"])) return ParseComplex<InputTextMessageContent>(value);
    if (internal::IsPresent(value["payload"]) || internal::IsPresent(value["currency"]) ||
        internal::IsPresent(value["prices"]))
        return ParseComplex<InputInvoiceMessageContent>(value);
    if (internal::IsPresent(value["phone_number"])) return ParseComplex<InputContactMessageContent>(value);
    if (internal::IsPresent(value["title"]) || internal::IsPresent(value["address"]))
        return ParseComplex<InputVenueMessageContent>(value);
    if (internal::IsPresent(value["latitude"]) || internal::IsPresent(value["longitude"]))
        return ParseComplex<InputLocationMessageContent>(value);
    throw std::runtime_error("Unknown InputMessageContent payload");
}

void Serialize(const InputMessageContent& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
