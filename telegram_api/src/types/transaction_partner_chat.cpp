#include <tg/types/chat.hpp>
#include <tg/types/gift.hpp>
#include <tg/types/transaction_partner_chat.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"
namespace tg {

TransactionPartnerChat Parse(const Value& value, To<TransactionPartnerChat>) {
    TransactionPartnerChat obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.chat = ParseComplex<Chat>(value["chat"]);
    obj.gift = ParseComplex<Optional<Gift>>(value["gift"]);
    return obj;
}

void Serialize(const TransactionPartnerChat& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "chat", obj.chat);
    internal::Put(builder, "gift", obj.gift);
}

}  // namespace tg
