#include <tg/types/copy_text_button.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

CopyTextButton Parse(const Value& value, To<CopyTextButton>) {
    CopyTextButton obj{};
    obj.text = ParseComplex<String>(value["text"]);
    return obj;
}

void Serialize(const CopyTextButton& obj, ValueBuilder& builder) { internal::Put(builder, "text", obj.text); }

}  // namespace tg
