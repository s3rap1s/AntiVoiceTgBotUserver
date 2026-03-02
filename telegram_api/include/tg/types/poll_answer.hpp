#pragma once

#include <tg/types/chat.hpp>
#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct PollAnswer {
    String poll_id;
    Optional<Chat> voter_chat;
    Optional<User> user;
    Optional<Integer> option_ids;
};

PollAnswer Parse(const Value& value, To<PollAnswer>);

}  // namespace tg
