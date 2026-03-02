#pragma once

#include <tg/types/common.hpp>
#include <tg/types/user.hpp>

namespace tg {

struct PaidMediaPurchased {
    User from;
    String paid_media_payload;
};

PaidMediaPurchased Parse(const Value& value, To<PaidMediaPurchased>);

}  // namespace tg
