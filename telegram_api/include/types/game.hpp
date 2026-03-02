#pragma once

#include <types/animation.hpp>
#include <types/common.hpp>
#include <types/message_entity.hpp>
#include <types/photo_size.hpp>

namespace tg {

struct Game {
    String title;
    Array<PhotoSize> photo;
    Optional<String> text;
    Optional<Array<MessageEntity>> text_entities;
    Optional<Animation> animation;
};

Game Parse(const Value& value, To<Game>);

}  // namespace tg
