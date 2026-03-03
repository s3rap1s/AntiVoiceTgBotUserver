#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct KeyboardButtonPollType {
    Optional<String> type;
};

KeyboardButtonPollType Parse(const Value& value, To<KeyboardButtonPollType>);

void Serialize(const KeyboardButtonPollType& obj, ValueBuilder& builder);

}  // namespace tg
