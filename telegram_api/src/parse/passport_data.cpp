#include <types/encrypted_credentials.hpp>
#include <types/encrypted_passport_element.hpp>
#include <types/passport_data.hpp>

#include "common.hpp"

namespace tg {

PassportData Parse(const Value& value, To<PassportData>) {
    PassportData obj{};
    obj.data = ParseComplex<Array<EncryptedPassportElement>>(value["data"]);
    obj.credentials = ParseComplex<EncryptedCredentials>(value["credentials"]);
    return obj;
}

}  // namespace tg
