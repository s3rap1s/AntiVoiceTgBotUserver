#include <tg/types/business_bot_rights.hpp>
#include <tg/types/business_connection.hpp>
#include <tg/types/user.hpp>

#include "common.hpp"

namespace tg {

BusinessConnection Parse(const Value& value, To<BusinessConnection>) {
    BusinessConnection obj{};
    obj.id = ParseComplex<String>(value["id"]);
    obj.user = ParseComplex<User>(value["user"]);
    obj.user_chat_id = ParseComplex<Integer>(value["user_chat_id"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.rights = ParseComplex<Optional<BusinessBotRights>>(value["rights"]);
    obj.is_enabled = ParseComplex<Boolean>(value["is_enabled"]);
    return obj;
}

}  // namespace tg
