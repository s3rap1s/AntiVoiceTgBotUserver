#pragma once

#include <types/common.hpp>

namespace tg {

struct Chat {
    Integer id;
    String type;
    Optional<String> title;
    Optional<String> username;
    Optional<String> first_name;
    Optional<String> last_name;
    OptionalTrue is_forum;
    OptionalTrue is_direct_message;
};

Chat Parse(const Value& value, To<Chat>);

}  // namespace tg
