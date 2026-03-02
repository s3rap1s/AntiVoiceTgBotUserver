#include <types/copy_text_button.hpp>

#include "common.hpp"

namespace tg {

CopyTextButton Parse(const Value& value, To<CopyTextButton>) {
    CopyTextButton obj{};
    obj.text = ParseComplex<String>(value["text"]);
    return obj;
}

}  // namespace tg
