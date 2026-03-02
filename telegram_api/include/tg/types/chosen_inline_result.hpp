#pragma once

#include <tg/types/common.hpp>
#include <tg/types/location.hpp>
#include <tg/types/user.hpp>

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
