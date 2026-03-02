#include <tg/types/callback_game.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/photo_size.hpp>

#include "common.hpp"

namespace tg {

CallbackGame Parse(const Value& value, To<CallbackGame>) {
    CallbackGame obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.description = ParseComplex<String>(value["description"]);
    obj.photo = ParseComplex<Array<PhotoSize>>(value["photo"]);
    obj.text = ParseComplex<Optional<String>>(value["text"]);
    obj.text_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    obj.animation = ParseComplex<Optional<String>>(value["animation"]);
    return obj;
}

}  // namespace tg
