#include <tg/types/callback_query.hpp>
#include <tg/types/maybe_inaccessible_message.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

CallbackQuery Parse(const Value& value, To<CallbackQuery>) {
    CallbackQuery obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.from = ParseComplex<User>(value["from"]);
    obj.message = ParseComplex<Optional<MaybeInaccessibleMessage>>(value["message"]);
    obj.inline_message_id = ParseComplex<Optional<String>>(value["inline_message_id"]);
    obj.chat_instance = ParseComplex<String>(value["chat_instance"]);
    obj.data = ParseComplex<Optional<String>>(value["data"]);
    obj.game_short_name = ParseComplex<Optional<String>>(value["game_short_name"]);
    return obj;
}

void Serialize(const CallbackQuery& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "from", obj.from);
    internal::Put(builder, "message", obj.message);
    internal::Put(builder, "inline_message_id", obj.inline_message_id);
    internal::Put(builder, "chat_instance", obj.chat_instance);
    internal::Put(builder, "data", obj.data);
    internal::Put(builder, "game_short_name", obj.game_short_name);
}

}  // namespace tg
