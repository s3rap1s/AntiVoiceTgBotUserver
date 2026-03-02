#pragma once

#include <types/common.hpp>
#include <types/message_entity.hpp>

namespace tg {

struct InputMediaAudio {
    String type;
    String media;
    Optional<String> thumbnail;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> duration;
    Optional<String> performer;
    Optional<String> title;
};

InputMediaAudio Parse(const Value& value, To<InputMediaAudio>);

}  // namespace tg
