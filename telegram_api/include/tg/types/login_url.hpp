#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct LoginUrl {
    String url;
    Optional<String> forward_text;
    Optional<String> bot_username;
    Optional<Boolean> request_write_access;
};

LoginUrl Parse(const Value& value, To<LoginUrl>);

}  // namespace tg
