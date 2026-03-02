#include <types/user.hpp>
#include <types/video_chat_participants_invited.hpp>

#include "common.hpp"

namespace tg {

VideoChatParticipantsInvited Parse(const Value& value,
                                   To<VideoChatParticipantsInvited>) {
    VideoChatParticipantsInvited obj{};
    obj.users = ParseComplex<Array<User>>(value["users"]);
    return obj;
}

}  // namespace tg
