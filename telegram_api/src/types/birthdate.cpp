#include <tg/types/birthdate.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

Birthdate Parse(const Value& value, To<Birthdate>) {
    Birthdate obj{};
    obj.day = ParseComplex<Integer>(value["day"]);
    obj.month = ParseComplex<Integer>(value["month"]);
    obj.year = ParseComplex<Integer>(value["year"]);
    return obj;
}

void Serialize(const Birthdate& obj, ValueBuilder& builder) {
    internal::Put(builder, "day", obj.day);
    internal::Put(builder, "month", obj.month);
    internal::Put(builder, "year", obj.year);
}

}  // namespace tg
