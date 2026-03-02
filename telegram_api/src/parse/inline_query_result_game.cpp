#include <types/inline_keyboard_markup.hpp>
#include <types/inline_query_result_game.hpp>

#include "common.hpp"

namespace tg {

InlineQueryResultGame Parse(const Value& value, To<InlineQueryResultGame>) {
    InlineQueryResultGame obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.game_short_name = ParseComplex<String>(value["game_short_name"]);
    obj.reply_markup =
        ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    return obj;
}

}  // namespace tg
