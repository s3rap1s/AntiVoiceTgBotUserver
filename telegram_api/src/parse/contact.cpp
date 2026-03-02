#include <tg/types/contact.hpp>

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

}  // namespace tg
