#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>

namespace tg {

struct ReplyKeyboardRemove {
    OptionalTrue remove_keyboard;
    Optional<Boolean> selective;
};

ReplyKeyboardRemove Parse(const Value& value, To<ReplyKeyboardRemove>);

void Serialize(const ReplyKeyboardRemove& obj, ValueBuilder& builder);

}  // namespace tg
