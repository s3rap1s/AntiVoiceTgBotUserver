#include <tg/types/gift.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/owned_gift_regular.hpp>
#include <tg/types/user.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

OwnedGiftRegular Parse(const Value& value, To<OwnedGiftRegular>) {
    OwnedGiftRegular obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.gift = ParseComplex<Gift>(value["gift"]);
    obj.owned_gift_id = ParseComplex<Optional<String>>(value["owned_gift_id"]);
    obj.sender_user = ParseComplex<Optional<User>>(value["sender_user"]);
    obj.date = ParseComplex<Integer>(value["date"]);
    obj.text = ParseComplex<Optional<String>>(value["text"]);
    obj.entities = ParseComplex<Optional<Array<MessageEntity>>>(value["entities"]);
    obj.is_private = ParseComplex<OptionalTrue>(value["is_private"]);
    obj.is_saved = ParseComplex<OptionalTrue>(value["is_saved"]);
    obj.can_be_upgraded = ParseComplex<OptionalTrue>(value["can_be_upgraded"]);
    obj.was_refunded = ParseComplex<OptionalTrue>(value["was_refunded"]);
    obj.convert_star_count = ParseComplex<Optional<Integer>>(value["convert_star_count"]);
    obj.prepaid_upgrade_star_count = ParseComplex<Optional<Integer>>(value["prepaid_upgrade_star_count"]);
    obj.is_upgrade_separate = ParseComplex<OptionalTrue>(value["is_upgrade_separate"]);
    obj.unique_gift_number = ParseComplex<Optional<Integer>>(value["unique_gift_number"]);
    return obj;
}

void Serialize(const OwnedGiftRegular& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "gift", obj.gift);
    internal::Put(builder, "owned_gift_id", obj.owned_gift_id);
    internal::Put(builder, "sender_user", obj.sender_user);
    internal::Put(builder, "date", obj.date);
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "entities", obj.entities);
    internal::Put(builder, "is_private", obj.is_private);
    internal::Put(builder, "is_saved", obj.is_saved);
    internal::Put(builder, "can_be_upgraded", obj.can_be_upgraded);
    internal::Put(builder, "was_refunded", obj.was_refunded);
    internal::Put(builder, "convert_star_count", obj.convert_star_count);
    internal::Put(builder, "prepaid_upgrade_star_count", obj.prepaid_upgrade_star_count);
    internal::Put(builder, "is_upgrade_separate", obj.is_upgrade_separate);
    internal::Put(builder, "unique_gift_number", obj.unique_gift_number);
}

}  // namespace tg
