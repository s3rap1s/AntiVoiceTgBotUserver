#include <types/response_parameters.hpp>

#include "common.hpp"

namespace tg {

ResponseParameters Parse(const Value& value, To<ResponseParameters>) {
    ResponseParameters obj{};
    obj.migrate_to_chat_id =
        ParseComplex<Optional<Integer>>(value["migrate_to_chat_id"]);
    obj.retry_after = ParseComplex<Optional<Integer>>(value["retry_after"]);
    return obj;
}

}  // namespace tg
