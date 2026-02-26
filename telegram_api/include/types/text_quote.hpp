#pragma once

#include "common.hpp"
#include "message_entity.hpp"

namespace tg {

struct TextQuote {
    String text;
    Optional<Array<MessageEntity>> entities;
};

TextQuote Parse(const Value& value, To<TextQuote>);

}  // namespace tg
