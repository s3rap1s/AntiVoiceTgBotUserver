#include <types/gift_background.hpp>

#include "common.hpp"

namespace tg {

GiftBackground Parse(const Value& value, To<GiftBackground>) {
    GiftBackground obj{};
    obj.center_color = ParseComplex<Integer>(value["center_color"]);
    obj.edge_color = ParseComplex<Integer>(value["edge_color"]);
    obj.text_color = ParseComplex<Integer>(value["text_color"]);
    return obj;
}

}  // namespace tg
