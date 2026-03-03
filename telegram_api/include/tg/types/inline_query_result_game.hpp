#pragma once

#include <userver/formats/json/value_builder.hpp>

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

void Serialize(const InlineQueryResultGame& obj, ValueBuilder& builder);

}  // namespace tg
