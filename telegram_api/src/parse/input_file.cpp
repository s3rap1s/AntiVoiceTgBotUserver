#include <types/input_file.hpp>

#include "common.hpp"

namespace tg {

InputFile Parse(const Value& value, To<InputFile>) {
    (void)value;
    return InputFile{};
}

}  // namespace tg
