#pragma once

#include <tg/types/common.hpp>
#include <tg/types/labeled_price.hpp>

namespace tg {

struct InputInvoiceMessageContent {
    String title;
    String description;
    String payload;
    Optional<String> provider_token;
    String currency;
    Optional<Array<LabeledPrice>> prices;
    Optional<Integer> max_tip_amount;
    Optional<Array<Integer>> suggested_tip_amounts;
    Optional<String> provider_data;
    Optional<String> photo_url;
    Optional<Boolean> photo_size;
    Optional<Integer> photo_width;
    Optional<Integer> photo_height;
    Optional<Boolean> need_name;
    Optional<Boolean> need_phone_number;
    Optional<Boolean> need_email;
    Optional<Boolean> need_shipping_address;
    Optional<Boolean> send_phone_number_to_provider;
    Optional<Boolean> send_email_to_provider;
    Optional<Boolean> is_flexible;
};

InputInvoiceMessageContent Parse(const Value& value,
                                 To<InputInvoiceMessageContent>);

}  // namespace tg
