#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct VideoChatParticipantsInvited {
    Array<User> users;
};

VideoChatParticipantsInvited Parse(const Value& value, To<VideoChatParticipantsInvited>);

void Serialize(const VideoChatParticipantsInvited& obj, ValueBuilder& builder);

}  // namespace tg
