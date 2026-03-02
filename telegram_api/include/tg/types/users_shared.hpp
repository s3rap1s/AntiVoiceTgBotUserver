#pragma once

#include <tg/types/common.hpp>
#include <tg/types/shared_user.hpp>

namespace tg {

struct UsersShared {
    Integer request_id;
    Array<SharedUser> users;
};

UsersShared Parse(const Value& value, To<UsersShared>);

}  // namespace tg
