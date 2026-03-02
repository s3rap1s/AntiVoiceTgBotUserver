#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct EncryptedCredentials {
    String data;
    String hash;
    String secret;
};

EncryptedCredentials Parse(const Value& value, To<EncryptedCredentials>);

}  // namespace tg
