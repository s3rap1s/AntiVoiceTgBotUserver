#pragma once

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

}  // namespace tg
