#include <tg/types/gift_background.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

GiftBackground Parse(const Value& value, To<GiftBackground>) {
    GiftBackground obj{};
    obj.center_color = ParseComplex<Integer>(value["center_color"]);
    obj.edge_color = ParseComplex<Integer>(value["edge_color"]);
    obj.text_color = ParseComplex<Integer>(value["text_color"]);
    return obj;
}

void Serialize(const GiftBackground& obj, ValueBuilder& builder) {
    internal::Put(builder, "center_color", obj.center_color);
    internal::Put(builder, "edge_color", obj.edge_color);
    internal::Put(builder, "text_color", obj.text_color);
}

}  // namespace tg
