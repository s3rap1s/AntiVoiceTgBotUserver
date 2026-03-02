#include <types/chat.hpp>
#include <types/poll_answer.hpp>
#include <types/user.hpp>

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

}  // namespace tg
