#include <tg/types/business_opening_hours.hpp>
#include <tg/types/business_opening_hours_interval.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BusinessOpeningHours Parse(const Value& value, To<BusinessOpeningHours>) {
    BusinessOpeningHours obj{};
    obj.time_zone_name = ParseComplex<String>(value["time_zone_name"]);
    obj.opening_hours = ParseComplex<Array<BusinessOpeningHoursInterval>>(value["opening_hours"]);
    return obj;
}

void Serialize(const BusinessOpeningHours& obj, ValueBuilder& builder) {
    internal::Put(builder, "time_zone_name", obj.time_zone_name);
    internal::Put(builder, "opening_hours", obj.opening_hours);
}

}  // namespace tg
