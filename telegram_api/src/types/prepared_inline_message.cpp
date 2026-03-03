#include <tg/types/prepared_inline_message.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PreparedInlineMessage Parse(const Value& value, To<PreparedInlineMessage>) {
    PreparedInlineMessage obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.expiration_date = ParseComplex<Integer>(value["expiration_date"]);
    return obj;
}

void Serialize(const PreparedInlineMessage& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "expiration_date", obj.expiration_date);
}

}  // namespace tg
