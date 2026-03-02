#include <tg/types/shared_user.hpp>
#include <tg/types/users_shared.hpp>

#include "common.hpp"

namespace tg {

UsersShared Parse(const Value& value, To<UsersShared>) {
    UsersShared obj{};
    obj.request_id = ParseComplex<Integer>(value["request_id"]);
    obj.users = ParseComplex<Array<SharedUser>>(value["users"]);
    return obj;
}

}  // namespace tg
