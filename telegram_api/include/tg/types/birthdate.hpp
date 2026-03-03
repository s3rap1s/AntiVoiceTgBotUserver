#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct Birthdate {
    Integer day;
    Integer month;
    Integer year;
};

Birthdate Parse(const Value& value, To<Birthdate>);

void Serialize(const Birthdate& obj, ValueBuilder& builder);

}  // namespace tg
