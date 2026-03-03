#include <tg/types/chat.hpp>
#include <tg/types/unique_gift.hpp>
#include <tg/types/unique_gift_backdrop.hpp>
#include <tg/types/unique_gift_colors.hpp>
#include <tg/types/unique_gift_model.hpp>
#include <tg/types/unique_gift_symbol.hpp>

#include "../internal/json_builder.hpp"
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
    obj.is_from_blockchain = ParseComplex<OptionalTrue>(value["is_from_blockchain"]);
    obj.colors = ParseComplex<UniqueGiftColors>(value["colors"]);
    obj.publisher_chat = ParseComplex<Optional<Chat>>(value["publisher_chat"]);
    return obj;
}

void Serialize(const UniqueGift& obj, ValueBuilder& builder) {
    internal::Put(builder, "gift_id", obj.gift_id);
    internal::Put(builder, "base_name", obj.base_name);
    internal::Put(builder, "name", obj.name);
    internal::Put(builder, "number", obj.number);
    internal::Put(builder, "model", obj.model);
    internal::Put(builder, "symbol", obj.symbol);
    internal::Put(builder, "backdrop", obj.backdrop);
    internal::Put(builder, "is_premium", obj.is_premium);
    internal::Put(builder, "is_burned", obj.is_burned);
    internal::Put(builder, "is_from_blockchain", obj.is_from_blockchain);
    internal::Put(builder, "colors", obj.colors);
    internal::Put(builder, "publisher_chat", obj.publisher_chat);
}

}  // namespace tg
