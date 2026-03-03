#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/shared_user.hpp>

namespace tg {

struct UsersShared {
    Integer request_id;
    Array<SharedUser> users;
};

UsersShared Parse(const Value& value, To<UsersShared>);

void Serialize(const UsersShared& obj, ValueBuilder& builder);

}  // namespace tg
