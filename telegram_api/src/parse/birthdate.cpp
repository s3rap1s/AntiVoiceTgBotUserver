#include <tg/types/birthdate.hpp>

#include "common.hpp"

namespace tg {

Birthdate Parse(const Value& value, To<Birthdate>) {
    Birthdate obj{};
    obj.day = ParseComplex<Integer>(value["day"]);
    obj.month = ParseComplex<Integer>(value["month"]);
    obj.year = ParseComplex<Integer>(value["year"]);
    return obj;
}

}  // namespace tg
