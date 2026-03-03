#include <tg/types/encrypted_passport_element.hpp>
#include <tg/types/passport_file.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

EncryptedPassportElement Parse(const Value& value, To<EncryptedPassportElement>) {
    EncryptedPassportElement obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.data = ParseComplex<Optional<String>>(value["data"]);
    obj.phone_number = ParseComplex<Optional<String>>(value["phone_number"]);
    obj.email = ParseComplex<Optional<String>>(value["email"]);
    obj.files = ParseComplex<Optional<Array<PassportFile>>>(value["files"]);
    obj.front_side = ParseComplex<Optional<PassportFile>>(value["front_side"]);
    obj.reverse_side = ParseComplex<Optional<PassportFile>>(value["reverse_side"]);
    obj.selfie = ParseComplex<Optional<PassportFile>>(value["selfie"]);
    obj.translation = ParseComplex<Array<PassportFile>>(value["translation"]);
    obj.hash = ParseComplex<String>(value["hash"]);
    return obj;
}

void Serialize(const EncryptedPassportElement& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "data", obj.data);
    internal::Put(builder, "phone_number", obj.phone_number);
    internal::Put(builder, "email", obj.email);
    internal::Put(builder, "files", obj.files);
    internal::Put(builder, "front_side", obj.front_side);
    internal::Put(builder, "reverse_side", obj.reverse_side);
    internal::Put(builder, "selfie", obj.selfie);
    internal::Put(builder, "translation", obj.translation);
    internal::Put(builder, "hash", obj.hash);
}

}  // namespace tg
