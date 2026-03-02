#include <types/chat.hpp>
#include <types/unique_gift.hpp>
#include <types/unique_gift_backdrop.hpp>
#include <types/unique_gift_colors.hpp>
#include <types/unique_gift_model.hpp>
#include <types/unique_gift_symbol.hpp>

#include "common.hpp"

namespace tg {

UniqueGift Parse(const Value& value, To<UniqueGift>) {
    UniqueGift obj{};
    obj.gift_id = ParseComplex<String>(value["gift_id"]);
    obj.base_name = ParseComplex<String>(value["base_name"]);
    obj.name = ParseComplex<String>(value["name"]);
    obj.number = ParseComplex<Integer>(value["number"]);
    obj.model = ParseComplex<UniqueGiftModel>(value["model"]);
    obj.symbol = ParseComplex<UniqueGiftSymbol>(value["symbol"]);
    obj.backdrop = ParseComplex<UniqueGiftBackdrop>(value["backdrop"]);
    obj.is_premium = ParseComplex<OptionalTrue>(value["is_premium"]);
    obj.is_burned = ParseComplex<OptionalTrue>(value["is_burned"]);
    obj.is_from_blockchain =
        ParseComplex<OptionalTrue>(value["is_from_blockchain"]);
    obj.colors = ParseComplex<UniqueGiftColors>(value["colors"]);
    obj.publisher_chat = ParseComplex<Optional<Chat>>(value["publisher_chat"]);
    return obj;
}

}  // namespace tg
