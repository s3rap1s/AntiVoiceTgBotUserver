#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct PreparedInlineMessage {
    String id;
    Integer expiration_date;
};

PreparedInlineMessage Parse(const Value& value, To<PreparedInlineMessage>);

}  // namespace tg
