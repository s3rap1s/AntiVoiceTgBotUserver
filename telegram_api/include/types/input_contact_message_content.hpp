#pragma once

#include <types/common.hpp>

namespace tg {

struct InputContactMessageContent {
    String phone_number;
    String first_name;
    Optional<String> last_name;
    Optional<String> vcard;
};

InputContactMessageContent Parse(const Value& value,
                                 To<InputContactMessageContent>);

}  // namespace tg
