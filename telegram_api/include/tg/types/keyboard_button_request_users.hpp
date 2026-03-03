#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct KeyboardButtonRequestUsers {
    Integer request_id;
    Optional<Boolean> user_is_bot;
    Optional<Boolean> user_is_premium;
    Optional<Integer> max_quantity;
    Optional<Boolean> request_name;
    Optional<Boolean> request_username;
    Optional<Boolean> request_photo;
};

KeyboardButtonRequestUsers Parse(const Value& value, To<KeyboardButtonRequestUsers>);

void Serialize(const KeyboardButtonRequestUsers& obj, ValueBuilder& builder);

}  // namespace tg
