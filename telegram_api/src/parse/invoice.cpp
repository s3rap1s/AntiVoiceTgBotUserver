#include <tg/types/invoice.hpp>

#include "common.hpp"

namespace tg {

Invoice Parse(const Value& value, To<Invoice>) {
    Invoice obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.description = ParseComplex<String>(value["description"]);
    obj.start_parameter = ParseComplex<String>(value["start_parameter"]);
    obj.currency = ParseComplex<String>(value["currency"]);
    obj.total_amount = ParseComplex<Integer>(value["total_amount"]);
    return obj;
}

}  // namespace tg
