#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct VideoChatParticipantsInvited {
    Array<User> users;
};

VideoChatParticipantsInvited Parse(const Value& value,
                                   To<VideoChatParticipantsInvited>);

}  // namespace tg
