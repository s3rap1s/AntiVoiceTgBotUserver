#pragma once

#include "common.hpp"
#include "location.hpp"
#include "user.hpp"

namespace tg {

struct ChosenInlineResult {
    String result_id;
    User from;
    Optional<Location> location;
    Optional<String> inline_message_id;
    Optional<String> query;
};

ChosenInlineResult Parse(const Value& value, To<ChosenInlineResult>);

}  // namespace tg
