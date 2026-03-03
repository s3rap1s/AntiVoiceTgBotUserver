#include <tg/types/callback_game.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/photo_size.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

CallbackGame Parse(const Value& value, To<CallbackGame>) {
    CallbackGame obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.description = ParseComplex<String>(value["description"]);
    obj.photo = ParseComplex<Array<PhotoSize>>(value["photo"]);
    obj.text = ParseComplex<Optional<String>>(value["text"]);
    obj.text_entities = ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    obj.animation = ParseComplex<Optional<String>>(value["animation"]);
    return obj;
}

void Serialize(const CallbackGame& obj, ValueBuilder& builder) {
    internal::Put(builder, "title", obj.title);
    internal::Put(builder, "description", obj.description);
    internal::Put(builder, "photo", obj.photo);
    internal::Put(builder, "text", obj.text);
    internal::Put(builder, "text_entities", obj.text_entities);
    internal::Put(builder, "animation", obj.animation);
}

}  // namespace tg
