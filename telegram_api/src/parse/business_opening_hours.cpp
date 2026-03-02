#include <types/business_opening_hours.hpp>
#include <types/business_opening_hours_interval.hpp>

#include "common.hpp"

namespace tg {

BusinessOpeningHours Parse(const Value& value, To<BusinessOpeningHours>) {
    BusinessOpeningHours obj{};
    obj.time_zone_name = ParseComplex<String>(value["time_zone_name"]);
    obj.opening_hours = ParseComplex<Array<BusinessOpeningHoursInterval>>(
        value["opening_hours"]);
    return obj;
}

}  // namespace tg
