#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct Invoice {
    String title;
    String description;
    String start_parameter;
    String currency;
    Integer total_amount;
};

Invoice Parse(const Value& value, To<Invoice>);

void Serialize(const Invoice& obj, ValueBuilder& builder);

}  // namespace tg
