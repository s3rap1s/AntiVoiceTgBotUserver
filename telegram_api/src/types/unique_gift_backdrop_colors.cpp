#include <tg/types/unique_gift_backdrop_colors.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UniqueGiftBackdropColors Parse(const Value& value, To<UniqueGiftBackdropColors>) {
    UniqueGiftBackdropColors obj{};
    obj.center_color = ParseComplex<Integer>(value["center_color"]);
    obj.edge_color = ParseComplex<Integer>(value["edge_color"]);
    obj.symbol_color = ParseComplex<Integer>(value["symbol_color"]);
    obj.text_color = ParseComplex<Integer>(value["text_color"]);
    return obj;
}

void Serialize(const UniqueGiftBackdropColors& obj, ValueBuilder& builder) {
    internal::Put(builder, "center_color", obj.center_color);
    internal::Put(builder, "edge_color", obj.edge_color);
    internal::Put(builder, "symbol_color", obj.symbol_color);
    internal::Put(builder, "text_color", obj.text_color);
}

}  // namespace tg
