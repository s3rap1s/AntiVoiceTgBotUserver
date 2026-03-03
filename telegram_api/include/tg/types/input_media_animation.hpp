#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct InputMediaAnimation {
    String type;
    String media;
    Optional<String> thumbnail;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<Boolean> width;
    Optional<Boolean> height;
    Optional<Boolean> duration;
    Optional<Boolean> has_spoiler;
};

InputMediaAnimation Parse(const Value& value, To<InputMediaAnimation>);

void Serialize(const InputMediaAnimation& obj, ValueBuilder& builder);

}  // namespace tg
