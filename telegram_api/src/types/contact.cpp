#include <tg/types/contact.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Contact Parse(const Value& value, To<Contact>) {
    Contact obj{};
    obj.photo_number = ParseComplex<String>(value["photo_number"]);
    obj.first_name = ParseComplex<String>(value["first_name"]);
    obj.last_name = ParseComplex<Optional<String>>(value["last_name"]);
    obj.user_id = ParseComplex<Optional<Integer>>(value["user_id"]);
    obj.vcard = ParseComplex<Optional<String>>(value["vcard"]);
    return obj;
}

void Serialize(const Contact& obj, ValueBuilder& builder) {
    internal::Put(builder, "photo_number", obj.photo_number);
    internal::Put(builder, "first_name", obj.first_name);
    internal::Put(builder, "last_name", obj.last_name);
    internal::Put(builder, "user_id", obj.user_id);
    internal::Put(builder, "vcard", obj.vcard);
}

}  // namespace tg
