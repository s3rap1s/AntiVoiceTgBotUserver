#include <tg/types/encrypted_credentials.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

EncryptedCredentials Parse(const Value& value, To<EncryptedCredentials>) {
    EncryptedCredentials obj{};
    obj.data = ParseComplex<String>(value["data"]);
    obj.hash = ParseComplex<String>(value["hash"]);
    obj.secret = ParseComplex<String>(value["secret"]);
    return obj;
}

void Serialize(const EncryptedCredentials& obj, ValueBuilder& builder) {
    internal::Put(builder, "data", obj.data);
    internal::Put(builder, "hash", obj.hash);
    internal::Put(builder, "secret", obj.secret);
}

}  // namespace tg
