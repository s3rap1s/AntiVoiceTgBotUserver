#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct BusinessOpeningHoursInterval {
    Integer opening_minute;
    Integer closing_minute;
};

BusinessOpeningHoursInterval Parse(const Value& value, To<BusinessOpeningHoursInterval>);

void Serialize(const BusinessOpeningHoursInterval& obj, ValueBuilder& builder);

}  // namespace tg
