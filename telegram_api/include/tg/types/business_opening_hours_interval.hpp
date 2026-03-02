#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct BusinessOpeningHoursInterval {
    Integer opening_minute;
    Integer closing_minute;
};

BusinessOpeningHoursInterval Parse(const Value& value,
                                   To<BusinessOpeningHoursInterval>);

}  // namespace tg
