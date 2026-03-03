#include <tg/types/chat.hpp>
#include <tg/types/poll_answer.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PollAnswer Parse(const Value& value, To<PollAnswer>) {
    PollAnswer obj{};
    obj.poll_id = ParseComplex<String>(value["poll_id"]);
    obj.voter_chat = ParseComplex<Optional<Chat>>(value["voter_chat"]);
    obj.user = ParseComplex<Optional<User>>(value["user"]);
    obj.option_ids = ParseComplex<Optional<Integer>>(value["option_ids"]);
    return obj;
}

void Serialize(const PollAnswer& obj, ValueBuilder& builder) {
    internal::Put(builder, "poll_id", obj.poll_id);
    internal::Put(builder, "voter_chat", obj.voter_chat);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "option_ids", obj.option_ids);
}

}  // namespace tg
