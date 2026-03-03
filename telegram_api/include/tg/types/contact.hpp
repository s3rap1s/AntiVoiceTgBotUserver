#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct Contact {
    String photo_number;
    String first_name;
    Optional<String> last_name;
    Optional<Integer> user_id;
    Optional<String> vcard;
};

Contact Parse(const Value& value, To<Contact>);

void Serialize(const Contact& obj, ValueBuilder& builder);

}  // namespace tg
