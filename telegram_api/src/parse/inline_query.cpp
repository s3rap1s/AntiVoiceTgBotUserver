#include <types/inline_query.hpp>
#include <types/location.hpp>
#include <types/user.hpp>

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

}  // namespace tg
