#pragma once

#include <types/common.hpp>
#include <types/photo_size.hpp>

namespace tg {

struct SharedUser {
    Integer user_id;
    Optional<String> first_name;
    Optional<String> last_name;
    Optional<String> username;
    Optional<Array<PhotoSize>> photo;
};

SharedUser Parse(const Value& value, To<SharedUser>);

}  // namespace tg
