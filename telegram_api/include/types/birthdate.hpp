#pragma once

#include "common.hpp"

namespace tg {

struct Birthdate {
    Integer day;
    Integer month;
    Integer year;
};

Birthdate Parse(const Value& value, To<Birthdate>);

}  // namespace tg
