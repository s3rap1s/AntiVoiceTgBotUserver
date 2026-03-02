#include <tg/types/unique_gift_backdrop_colors.hpp>

#include "common.hpp"

namespace tg {

UniqueGiftBackdropColors Parse(const Value& value,
                               To<UniqueGiftBackdropColors>) {
    UniqueGiftBackdropColors obj{};
    obj.center_color = ParseComplex<Integer>(value["center_color"]);
    obj.edge_color = ParseComplex<Integer>(value["edge_color"]);
    obj.symbol_color = ParseComplex<Integer>(value["symbol_color"]);
    obj.text_color = ParseComplex<Integer>(value["text_color"]);
    return obj;
}

}  // namespace tg
