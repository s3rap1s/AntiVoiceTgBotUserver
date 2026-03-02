#pragma once

#include <types/common.hpp>
#include <types/encrypted_credentials.hpp>
#include <types/encrypted_passport_element.hpp>

namespace tg {

struct PassportData {
    Array<EncryptedPassportElement> data;
    EncryptedCredentials credentials;
};

PassportData Parse(const Value& value, To<PassportData>);

}  // namespace tg
