#include <tg/types/message_entity.hpp>
#include <tg/types/text_quote.hpp>

#include "common.hpp"

namespace tg {

TextQuote Parse(const Value& value, To<TextQuote>) {
    TextQuote obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["entities"]);
    return obj;
}

}  // namespace tg
