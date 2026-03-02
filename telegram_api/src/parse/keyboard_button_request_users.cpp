#include <tg/types/keyboard_button_request_users.hpp>

#include "common.hpp"

namespace tg {

KeyboardButtonRequestUsers Parse(const Value& value,
                                 To<KeyboardButtonRequestUsers>) {
    KeyboardButtonRequestUsers obj{};
    obj.request_id = ParseComplex<Integer>(value["request_id"]);
    obj.user_is_bot = ParseComplex<Optional<Boolean>>(value["user_is_bot"]);
    obj.user_is_premium =
        ParseComplex<Optional<Boolean>>(value["user_is_premium"]);
    obj.max_quantity = ParseComplex<Optional<Integer>>(value["max_quantity"]);
    obj.request_name = ParseComplex<Optional<Boolean>>(value["request_name"]);
    obj.request_username =
        ParseComplex<Optional<Boolean>>(value["request_username"]);
    obj.request_photo = ParseComplex<Optional<Boolean>>(value["request_photo"]);
    return obj;
}

}  // namespace tg
