#include <tg/types/input_file.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputFile Parse(const Value& value, To<InputFile>) {
    (void)value;
    return InputFile{};
}

void Serialize(const InputFile& obj, ValueBuilder& builder) {
    (void)obj;
    (void)builder;
}

}  // namespace tg
