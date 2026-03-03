#include <tg/types/business_opening_hours_interval.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

BusinessOpeningHoursInterval Parse(const Value& value, To<BusinessOpeningHoursInterval>) {
    BusinessOpeningHoursInterval obj{};
    obj.opening_minute = ParseComplex<Integer>(value["opening_minute"]);
    obj.closing_minute = ParseComplex<Integer>(value["closing_minute"]);
    return obj;
}

void Serialize(const BusinessOpeningHoursInterval& obj, ValueBuilder& builder) {
    internal::Put(builder, "opening_minute", obj.opening_minute);
    internal::Put(builder, "closing_minute", obj.closing_minute);
}

}  // namespace tg
