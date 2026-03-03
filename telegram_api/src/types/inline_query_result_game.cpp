#include <tg/types/inline_keyboard_markup.hpp>
#include <tg/types/inline_query_result_game.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InlineQueryResultGame Parse(const Value& value, To<InlineQueryResultGame>) {
    InlineQueryResultGame obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.id = ParseComplex<String>(value["id"]);
    obj.game_short_name = ParseComplex<String>(value["game_short_name"]);
    obj.reply_markup = ParseComplex<Optional<InlineKeyboardMarkup>>(value["reply_markup"]);
    return obj;
}

void Serialize(const InlineQueryResultGame& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "id", obj.id);
    internal::Put(builder, "game_short_name", obj.game_short_name);
    internal::Put(builder, "reply_markup", obj.reply_markup);
}

}  // namespace tg
