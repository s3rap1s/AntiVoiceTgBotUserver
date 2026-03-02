#pragma once

#include <types/common.hpp>
#include <types/passport_file.hpp>

namespace tg {

struct EncryptedPassportElement {
    String type;
    Optional<String> data;
    Optional<String> phone_number;
    Optional<String> email;
    Optional<Array<PassportFile>> files;
    Optional<PassportFile> front_side;
    Optional<PassportFile> reverse_side;
    Optional<PassportFile> selfie;
    Array<PassportFile> translation;
    String hash;
};

EncryptedPassportElement Parse(const Value& value,
                               To<EncryptedPassportElement>);

}  // namespace tg
