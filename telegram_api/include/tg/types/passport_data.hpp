#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/encrypted_credentials.hpp>
#include <tg/types/encrypted_passport_element.hpp>

namespace tg {

struct PassportData {
    Array<EncryptedPassportElement> data;
    EncryptedCredentials credentials;
};

PassportData Parse(const Value& value, To<PassportData>);

void Serialize(const PassportData& obj, ValueBuilder& builder);

}  // namespace tg
