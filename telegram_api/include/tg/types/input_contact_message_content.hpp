#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct InputContactMessageContent {
    String phone_number;
    String first_name;
    Optional<String> last_name;
    Optional<String> vcard;
};

InputContactMessageContent Parse(const Value& value, To<InputContactMessageContent>);

void Serialize(const InputContactMessageContent& obj, ValueBuilder& builder);

}  // namespace tg
