#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct DirectMessagesTopic {
    Integer topic_id;
    Optional<User> user;
};

DirectMessagesTopic Parse(const Value& value, To<DirectMessagesTopic>);

void Serialize(const DirectMessagesTopic& obj, ValueBuilder& builder);

}  // namespace tg
