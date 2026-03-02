#include <types/animation.hpp>
#include <types/game.hpp>
#include <types/message_entity.hpp>
#include <types/photo_size.hpp>

#include "common.hpp"

namespace tg {

Game Parse(const Value& value, To<Game>) {
    Game obj{};
    obj.title = ParseComplex<String>(value["title"]);
    obj.photo = ParseComplex<Array<PhotoSize>>(value["photo"]);
    obj.text = ParseComplex<Optional<String>>(value["text"]);
    obj.text_entities =
        ParseComplex<Optional<Array<MessageEntity>>>(value["text_entities"]);
    obj.animation = ParseComplex<Optional<Animation>>(value["animation"]);
    return obj;
}

}  // namespace tg
