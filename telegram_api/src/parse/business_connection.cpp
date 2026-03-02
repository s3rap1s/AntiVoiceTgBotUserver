#include <types/business_bot_rights.hpp>
#include <types/business_connection.hpp>
#include <types/user.hpp>

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
