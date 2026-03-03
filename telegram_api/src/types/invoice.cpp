#include <tg/types/invoice.hpp>

#include "../internal/json_builder.hpp"
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

void Serialize(const Invoice& obj, ValueBuilder& builder) {
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "description", obj.description);
    internal::Put(builder, "start_parameter", obj.start_parameter);
    internal::Put(builder, "currency", obj.currency);
    internal::Put(builder, "total_amount", obj.total_amount);
}

}  // namespace tg
