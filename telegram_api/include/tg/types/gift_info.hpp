#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/gift.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct GiftInfo {
    Gift gift;
    Optional<String> owned_gift_id;
    Optional<Integer> convert_star_count;
    Optional<Integer> prepaid_upgrade_star_count;
    OptionalTrue is_upgrade_separate;
    OptionalTrue can_be_upgraded;
    Optional<String> text;
    Optional<Array<MessageEntity>> entities;
    OptionalTrue is_private;
    Optional<Integer> unique_gift_number;
};

GiftInfo Parse(const Value& value, To<GiftInfo>);

void Serialize(const GiftInfo& obj, ValueBuilder& builder);

}  // namespace tg
