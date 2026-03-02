#include <tg/types/prepared_inline_message.hpp>

#include "common.hpp"

namespace tg {

PreparedInlineMessage Parse(const Value& value, To<PreparedInlineMessage>) {
    PreparedInlineMessage obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.expiration_date = ParseComplex<Integer>(value["expiration_date"]);
    return obj;
}

}  // namespace tg
