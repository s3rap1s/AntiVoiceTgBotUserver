#pragma once

#include <types/common.hpp>
#include <types/user.hpp>

namespace tg {

struct VideoChatParticipantsInvited {
    Array<User> users;
};

VideoChatParticipantsInvited Parse(const Value& value,
                                   To<VideoChatParticipantsInvited>);

}  // namespace tg
