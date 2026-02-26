#pragma once

#include "common.hpp"
#include "message_entity.hpp"
#include "photo_size.hpp"

namespace tg {

struct CallbackGame {
    String title;
    String description;
    Array<PhotoSize> photo;
    Optional<String> text;
    Optional<Array<MessageEntity>> text_entities;
    Optional<String> animation;
};

CallbackGame Parse(const Value& value, To<CallbackGame>);

}  // namespace tg
