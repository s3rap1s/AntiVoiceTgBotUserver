#include <tg/types/user.hpp>
#include <tg/types/video_chat_participants_invited.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

VideoChatParticipantsInvited Parse(const Value& value, To<VideoChatParticipantsInvited>) {
    VideoChatParticipantsInvited obj{};
    obj.users = ParseComplex<Array<User>>(value["users"]);
    return obj;
}

void Serialize(const VideoChatParticipantsInvited& obj, ValueBuilder& builder) {
    internal::Put(builder, "users", obj.users);
}

}  // namespace tg
