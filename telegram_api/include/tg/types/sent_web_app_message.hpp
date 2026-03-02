#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct SentWebAppMessage {
    Optional<String> inline_message_id;
};

SentWebAppMessage Parse(const Value& value, To<SentWebAppMessage>);

}  // namespace tg
