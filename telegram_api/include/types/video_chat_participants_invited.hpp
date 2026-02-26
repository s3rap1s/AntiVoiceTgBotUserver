#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct VideoChatParticipantsInvited {
    Array<User> users;
};

VideoChatParticipantsInvited Parse(const Value& value,
                                   To<VideoChatParticipantsInvited>);

}  // namespace tg
