#include <tg/types/photo_size.hpp>
#include <tg/types/shared_user.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const SharedUser& obj, ValueBuilder& builder) {
    internal::Put(builder, "user_id", obj.user_id);
    internal::Put(builder, "first_name", obj.first_name);
    internal::Put(builder, "last_name", obj.last_name);
    internal::Put(builder, "username", obj.username);
    internal::Put(builder, "photo", obj.photo);
}

}  // namespace tg
