#include <tg/types/gift.hpp>
#include <tg/types/gift_info.hpp>
#include <tg/types/message_entity.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

GiftInfo Parse(const Value& value, To<GiftInfo>) {
    GiftInfo obj{};
    obj.gift = ParseComplex<Gift>(value["gift"]);
    obj.owned_gift_id = ParseComplex<Optional<String>>(value["owned_gift_id"]);
    obj.convert_star_count = ParseComplex<Optional<Integer>>(value["convert_star_count"]);
    obj.prepaid_upgrade_star_count = ParseComplex<Optional<Integer>>(value["prepaid_upgrade_star_count"]);
    obj.is_upgrade_separate = ParseComplex<OptionalTrue>(value["is_upgrade_separate"]);
    obj.can_be_upgraded = ParseComplex<OptionalTrue>(value["can_be_upgraded"]);
    obj.text = ParseComplex<Optional<String>>(value["text"]);
    obj.entities = ParseComplex<Optional<Array<MessageEntity>>>(value["entities"]);
    obj.is_private = ParseComplex<OptionalTrue>(value["is_private"]);
    obj.unique_gift_number = ParseComplex<Optional<Integer>>(value["unique_gift_number"]);
    return obj;
}

void Serialize(const GiftInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "gift", obj.gift);
    internal::Put(builder, "owned_gift_id", obj.owned_gift_id);
    internal::Put(builder, "convert_star_count", obj.convert_star_count);
    internal::Put(builder, "prepaid_upgrade_star_count", obj.prepaid_upgrade_star_count);
    internal::Put(builder, "is_upgrade_separate", obj.is_upgrade_separate);
    internal::Put(builder, "can_be_upgraded", obj.can_be_upgraded);
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "entities", obj.entities);
    internal::Put(builder, "is_private", obj.is_private);
    internal::Put(builder, "unique_gift_number", obj.unique_gift_number);
}

}  // namespace tg
