#include <tg/types/chosen_inline_result.hpp>
#include <tg/types/location.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

ChosenInlineResult Parse(const Value& value, To<ChosenInlineResult>) {
    ChosenInlineResult obj{};
    obj.result_id = ParseComplex<String>(value["result_id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.location = ParseComplex<Optional<Location>>(value["location"]);
    obj.inline_message_id =
        ParseComplex<Optional<String>>(value["inline_message_id"]);
    obj.query = ParseComplex<Optional<String>>(value["query"]);
    return obj;
}

}  // namespace tg
