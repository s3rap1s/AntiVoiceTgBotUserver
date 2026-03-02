#include <tg/types/input_contact_message_content.hpp>
#include <tg/types/input_invoice_message_content.hpp>
#include <tg/types/input_location_message_content.hpp>
#include <tg/types/input_message_content.hpp>
#include <tg/types/input_text_message_content.hpp>
#include <tg/types/input_venue_message_content.hpp>

#include "common.hpp"

namespace tg {

InputMessageContent Parse(const Value& value, To<InputMessageContent>) {
    if (detail::IsPresent(value["message_text"]))
        return ParseComplex<InputTextMessageContent>(value);
    if (detail::IsPresent(value["payload"]) ||
        detail::IsPresent(value["currency"]) ||
        detail::IsPresent(value["prices"]))
        return ParseComplex<InputInvoiceMessageContent>(value);
    if (detail::IsPresent(value["phone_number"]))
        return ParseComplex<InputContactMessageContent>(value);
    if (detail::IsPresent(value["title"]) ||
        detail::IsPresent(value["address"]))
        return ParseComplex<InputVenueMessageContent>(value);
    if (detail::IsPresent(value["latitude"]) ||
        detail::IsPresent(value["longitude"]))
        return ParseComplex<InputLocationMessageContent>(value);
    throw std::runtime_error("Unknown InputMessageContent payload");
}

}  // namespace tg
