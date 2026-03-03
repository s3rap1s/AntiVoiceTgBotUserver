#include <tg/types/business_bot_rights.hpp>
#include <tg/types/business_connection.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const BusinessConnection& obj, ValueBuilder& builder) {
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "user", obj.user);
    internal::Put(builder, "user_chat_id", obj.user_chat_id);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "rights", obj.rights);
    internal::Put(builder, "is_enabled", obj.is_enabled);
}

}  // namespace tg
