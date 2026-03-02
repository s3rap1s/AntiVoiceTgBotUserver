#pragma once

#include <tg/types/animation.hpp>
#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/photo_size.hpp>

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
