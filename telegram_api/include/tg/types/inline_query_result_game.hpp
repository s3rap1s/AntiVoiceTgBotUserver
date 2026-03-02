#pragma once

#include <tg/types/common.hpp>
#include <tg/types/inline_keyboard_markup.hpp>

namespace tg {

struct InlineQueryResultGame {
    String type;
    String id;
    String game_short_name;
    Optional<InlineKeyboardMarkup> reply_markup;
};

InlineQueryResultGame Parse(const Value& value, To<InlineQueryResultGame>);

}  // namespace tg
