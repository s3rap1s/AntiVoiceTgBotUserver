#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct EncryptedCredentials {
    String data;
    String hash;
    String secret;
};

EncryptedCredentials Parse(const Value& value, To<EncryptedCredentials>);

void Serialize(const EncryptedCredentials& obj, ValueBuilder& builder);

}  // namespace tg
