#pragma once

#include "common.hpp"
#include "user.hpp"

namespace tg {

struct DirectMessagesTopic {
    Integer topic_id;
    Optional<User> user;
};

DirectMessagesTopic Parse(const Value& value, To<DirectMessagesTopic>);

}  // namespace tg
