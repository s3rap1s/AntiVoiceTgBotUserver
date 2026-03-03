#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/chat_boost.hpp>
#include <tg/types/common.hpp>

namespace tg {

struct UserChatBoosts {
    Array<ChatBoost> boosts;
};

UserChatBoosts Parse(const Value& value, To<UserChatBoosts>);

void Serialize(const UserChatBoosts& obj, ValueBuilder& builder);

}  // namespace tg
