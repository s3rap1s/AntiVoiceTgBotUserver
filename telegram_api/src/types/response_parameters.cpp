#include <tg/types/response_parameters.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ResponseParameters Parse(const Value& value, To<ResponseParameters>) {
    ResponseParameters obj{};
    obj.migrate_to_chat_id = ParseComplex<Optional<Integer>>(value["migrate_to_chat_id"]);
    obj.retry_after = ParseComplex<Optional<Integer>>(value["retry_after"]);
    return obj;
}

void Serialize(const ResponseParameters& obj, ValueBuilder& builder) {
    internal::Put(builder, "migrate_to_chat_id", obj.migrate_to_chat_id);
    internal::Put(builder, "retry_after", obj.retry_after);
}

}  // namespace tg
