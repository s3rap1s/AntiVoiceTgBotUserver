#include <tg/types/input_contact_message_content.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputContactMessageContent Parse(const Value& value, To<InputContactMessageContent>) {
    InputContactMessageContent obj{};
    obj.phone_number = ParseComplex<String>(value["phone_number"]);
    obj.first_name = ParseComplex<String>(value["first_name"]);
    obj.last_name = ParseComplex<Optional<String>>(value["last_name"]);
    obj.vcard = ParseComplex<Optional<String>>(value["vcard"]);
    return obj;
}

void Serialize(const InputContactMessageContent& obj, ValueBuilder& builder) {
    internal::Put(builder, "phone_number", obj.phone_number);
    internal::Put(builder, "first_name", obj.first_name);
    internal::Put(builder, "last_name", obj.last_name);
    internal::Put(builder, "vcard", obj.vcard);
}

}  // namespace tg
