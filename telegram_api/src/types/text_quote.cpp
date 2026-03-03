#include <tg/types/message_entity.hpp>
#include <tg/types/text_quote.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

TextQuote Parse(const Value& value, To<TextQuote>) {
    TextQuote obj{};
    obj.text = ParseComplex<String>(value["text"]);
    obj.entities = ParseComplex<Optional<Array<MessageEntity>>>(value["entities"]);
    return obj;
}

void Serialize(const TextQuote& obj, ValueBuilder& builder) {
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "entities", obj.entities);
}

}  // namespace tg
