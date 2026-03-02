#pragma once

#include <types/common.hpp>

namespace tg {

struct Invoice {
    String title;
    String description;
    String start_parameter;
    String currency;
    Integer total_amount;
};

Invoice Parse(const Value& value, To<Invoice>);

}  // namespace tg
