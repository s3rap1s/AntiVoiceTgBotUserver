#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct TextQuote {
    String text;
    Optional<Array<MessageEntity>> entities;
};

TextQuote Parse(const Value& value, To<TextQuote>);

void Serialize(const TextQuote& obj, ValueBuilder& builder);

}  // namespace tg
