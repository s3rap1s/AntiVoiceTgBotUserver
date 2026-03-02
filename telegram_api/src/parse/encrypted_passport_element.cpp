#include <types/encrypted_passport_element.hpp>
#include <types/passport_file.hpp>

#include "common.hpp"

namespace tg {

EncryptedPassportElement Parse(const Value& value,
                               To<EncryptedPassportElement>) {
    EncryptedPassportElement obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.data = ParseComplex<Optional<String>>(value["data"]);
    obj.phone_number = ParseComplex<Optional<String>>(value["phone_number"]);
    obj.email = ParseComplex<Optional<String>>(value["email"]);
    obj.files = ParseComplex<Optional<Array<PassportFile>>>(value["files"]);
    obj.front_side = ParseComplex<Optional<PassportFile>>(value["front_side"]);
    obj.reverse_side =
        ParseComplex<Optional<PassportFile>>(value["reverse_side"]);
    obj.selfie = ParseComplex<Optional<PassportFile>>(value["selfie"]);
    obj.translation = ParseComplex<Array<PassportFile>>(value["translation"]);
    obj.hash = ParseComplex<String>(value["hash"]);
    return obj;
}

}  // namespace tg
