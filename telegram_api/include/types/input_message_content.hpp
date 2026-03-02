#pragma once

#include <types/common.hpp>
#include <types/input_contact_message_content.hpp>
#include <types/input_invoice_message_content.hpp>
#include <types/input_location_message_content.hpp>
#include <types/input_text_message_content.hpp>
#include <types/input_venue_message_content.hpp>

namespace tg {

using InputMessageContent =
    OneOf<InputTextMessageContent, InputLocationMessageContent,
          InputVenueMessageContent, InputContactMessageContent,
          InputInvoiceMessageContent>;

InputMessageContent Parse(const Value& value, To<InputMessageContent>);

}  // namespace tg
