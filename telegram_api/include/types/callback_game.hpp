#pragma once

#include <types/common.hpp>
#include <types/message_entity.hpp>
#include <types/photo_size.hpp>

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
