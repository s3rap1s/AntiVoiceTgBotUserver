#include <tg/types/encrypted_credentials.hpp>

#include "common.hpp"

namespace tg {

EncryptedCredentials Parse(const Value& value, To<EncryptedCredentials>) {
    EncryptedCredentials obj{};
    obj.data = ParseComplex<String>(value["data"]);
    obj.hash = ParseComplex<String>(value["hash"]);
    obj.secret = ParseComplex<String>(value["secret"]);
    return obj;
}

}  // namespace tg
