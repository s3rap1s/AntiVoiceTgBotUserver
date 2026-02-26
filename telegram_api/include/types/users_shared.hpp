#pragma once

#include "common.hpp"
#include "shared_user.hpp"

namespace tg {

struct UsersShared {
    Integer request_id;
    Array<SharedUser> users;
};

UsersShared Parse(const Value& value, To<UsersShared>);

}  // namespace tg
