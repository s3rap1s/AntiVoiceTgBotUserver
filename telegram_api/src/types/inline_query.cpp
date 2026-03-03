#include <tg/types/inline_query.hpp>
#include <tg/types/location.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQuery Parse(const Value& value, To<InlineQuery>) {
    InlineQuery obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.query = ParseComplex<String>(value["query"]);
    obj.offset = ParseComplex<String>(value["offset"]);
    obj.chat_type = ParseComplex<Optional<String>>(value["chat_type"]);
    obj.location = ParseComplex<Optional<Location>>(value["location"]);
    return obj;
}

void Serialize(const InlineQuery& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "from", obj.from);
    internal::Put(builder, "query", obj.query);
    internal::Put(builder, "offset", obj.offset);
    internal::Put(builder, "chat_type", obj.chat_type);
    internal::Put(builder, "location", obj.location);
}

}  // namespace tg
