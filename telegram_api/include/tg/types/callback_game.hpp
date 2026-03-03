#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>
#include <tg/types/photo_size.hpp>

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

void Serialize(const CallbackGame& obj, ValueBuilder& builder);

}  // namespace tg
