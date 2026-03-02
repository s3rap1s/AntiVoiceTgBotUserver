#pragma once

#include <tg/types/business_opening_hours_interval.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct BusinessOpeningHours {
    String time_zone_name;
    Array<BusinessOpeningHoursInterval> opening_hours;
};

BusinessOpeningHours Parse(const Value& value, To<BusinessOpeningHours>);

}  // namespace tg
