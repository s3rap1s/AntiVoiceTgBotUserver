#include <tg/types/chat_member.hpp>
#include <tg/types/chat_member_administrator.hpp>
#include <tg/types/chat_member_banned.hpp>
#include <tg/types/chat_member_left.hpp>
#include <tg/types/chat_member_member.hpp>
#include <tg/types/chat_member_owner.hpp>
#include <tg/types/chat_member_restricted.hpp>

#include "common.hpp"

namespace tg {

ChatMember Parse(const Value& value, To<ChatMember>) {
    const auto status = ParseComplex<String>(value["status"]);
    if (status == "creator") return ParseComplex<ChatMemberOwner>(value);
    if (status == "administrator")
        return ParseComplex<ChatMemberAdministrator>(value);
    if (status == "member") return ParseComplex<ChatMemberMember>(value);
    if (status == "restricted")
        return ParseComplex<ChatMemberRestricted>(value);
    if (status == "left") return ParseComplex<ChatMemberLeft>(value);
    if (status == "kicked") return ParseComplex<ChatMemberBanned>(value);
    throw std::runtime_error("Unknown ChatMember status: " + status);
}

}  // namespace tg
