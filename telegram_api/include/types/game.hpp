#pragma once

#include "animation.hpp"
#include "common.hpp"
#include "message_entity.hpp"
#include "photo_size.hpp"

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
