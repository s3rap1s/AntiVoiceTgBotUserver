#include <tg/types/business_opening_hours_interval.hpp>

#include "common.hpp"

namespace tg {

BusinessOpeningHoursInterval Parse(const Value& value,
                                   To<BusinessOpeningHoursInterval>) {
    BusinessOpeningHoursInterval obj{};
    obj.opening_minute = ParseComplex<Integer>(value["opening_minute"]);
    obj.closing_minute = ParseComplex<Integer>(value["closing_minute"]);
    return obj;
}

}  // namespace tg
