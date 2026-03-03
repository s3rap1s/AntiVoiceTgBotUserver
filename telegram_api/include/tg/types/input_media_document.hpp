#pragma once

#include <userver/formats/json/value_builder.hpp>

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct InputMediaDocument {
    String type;
    String media;
    Optional<String> thumbnail;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> disable_content_type_detection;
};

InputMediaDocument Parse(const Value& value, To<InputMediaDocument>);

void Serialize(const InputMediaDocument& obj, ValueBuilder& builder);

}  // namespace tg
