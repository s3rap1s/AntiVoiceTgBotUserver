#include <tg/types/chosen_inline_result.hpp>
#include <tg/types/location.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

ChosenInlineResult Parse(const Value& value, To<ChosenInlineResult>) {
    ChosenInlineResult obj{};
    obj.result_id = ParseComplex<String>(value["result_id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.location = ParseComplex<Optional<Location>>(value["location"]);
    obj.inline_message_id = ParseComplex<Optional<String>>(value["inline_message_id"]);
    obj.query = ParseComplex<Optional<String>>(value["query"]);
    return obj;
}

void Serialize(const ChosenInlineResult& obj, ValueBuilder& builder) {
    internal::Put(builder, "result_id", obj.result_id);
    internal::Put(builder, "from", obj.from);
    internal::Put(builder, "location", obj.location);
    internal::Put(builder, "inline_message_id", obj.inline_message_id);
    internal::Put(builder, "query", obj.query);
}

}  // namespace tg
