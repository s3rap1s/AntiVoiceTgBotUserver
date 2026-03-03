#include <tg/types/encrypted_credentials.hpp>
#include <tg/types/encrypted_passport_element.hpp>
#include <tg/types/passport_data.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PassportData Parse(const Value& value, To<PassportData>) {
    PassportData obj{};
    obj.data = ParseComplex<Array<EncryptedPassportElement>>(value["data"]);
    obj.credentials = ParseComplex<EncryptedCredentials>(value["credentials"]);
    return obj;
}

void Serialize(const PassportData& obj, ValueBuilder& builder) {
    internal::Put(builder, "data", obj.data);
    internal::Put(builder, "credentials", obj.credentials);
}

}  // namespace tg
