#pragma once

#include <types/common.hpp>
#include <types/inline_keyboard_markup.hpp>

namespace tg {

struct InlineQueryResultGame {
    String type;
    String id;
    String game_short_name;
    Optional<InlineKeyboardMarkup> reply_markup;
};

InlineQueryResultGame Parse(const Value& value, To<InlineQueryResultGame>);

}  // namespace tg
