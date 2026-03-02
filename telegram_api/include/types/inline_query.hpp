#pragma once

#include <types/common.hpp>
#include <types/location.hpp>
#include <types/user.hpp>

namespace tg {

struct InlineQuery {
    String id;
    User from;
    String query;
    String offset;
    Optional<String> chat_type;
    Optional<Location> location;
};

InlineQuery Parse(const Value& value, To<InlineQuery>);

}  // namespace tg
