#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/photo_size.hpp>

namespace tg {

struct SharedUser {
    Integer user_id;
    Optional<String> first_name;
    Optional<String> last_name;
    Optional<String> username;
    Optional<Array<PhotoSize>> photo;
};

SharedUser Parse(const Value& value, To<SharedUser>);

void Serialize(const SharedUser& obj, ValueBuilder& builder);

}  // namespace tg
