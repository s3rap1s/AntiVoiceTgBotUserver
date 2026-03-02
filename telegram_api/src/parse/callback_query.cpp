#include <types/callback_query.hpp>
#include <types/maybe_inaccessible_message.hpp>
#include <types/user.hpp>

#include "common.hpp"

namespace tg {

CallbackQuery Parse(const Value& value, To<CallbackQuery>) {
    CallbackQuery obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.message =
        ParseComplex<Optional<MaybeInaccessibleMessage>>(value["message"]);
    obj.inline_message_id =
        ParseComplex<Optional<String>>(value["inline_message_id"]);
    obj.chat_instance = ParseComplex<String>(value["chat_instance"]);
    obj.data = ParseComplex<Optional<String>>(value["data"]);
    obj.game_short_name =
        ParseComplex<Optional<String>>(value["game_short_name"]);
    return obj;
}

}  // namespace tg
