#pragma once

#include "common.hpp"
#include "encrypted_credentials.hpp"
#include "encrypted_passport_element.hpp"

namespace tg {

struct PassportData {
    Array<EncryptedPassportElement> data;
    EncryptedCredentials credentials;
};

PassportData Parse(const Value& value, To<PassportData>);

}  // namespace tg
