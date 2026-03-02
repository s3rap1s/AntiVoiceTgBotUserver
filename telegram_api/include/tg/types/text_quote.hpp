#pragma once

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct TextQuote {
    String text;
    Optional<Array<MessageEntity>> entities;
};

TextQuote Parse(const Value& value, To<TextQuote>);

}  // namespace tg
