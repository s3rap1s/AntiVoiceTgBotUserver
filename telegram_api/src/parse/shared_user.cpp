#include <types/photo_size.hpp>
#include <types/shared_user.hpp>

#include "common.hpp"

namespace tg {

SharedUser Parse(const Value& value, To<SharedUser>) {
    SharedUser obj{};
    obj.user_id = ParseComplex<Integer>(value["user_id"]);
    obj.first_name = ParseComplex<Optional<String>>(value["first_name"]);
    obj.last_name = ParseComplex<Optional<String>>(value["last_name"]);
    obj.username = ParseComplex<Optional<String>>(value["username"]);
    obj.photo = ParseComplex<Optional<Array<PhotoSize>>>(value["photo"]);
    return obj;
}

}  // namespace tg
