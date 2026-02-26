#pragma once

#include "common.hpp"
#include "message_entity.hpp"

namespace tg {

struct InputMediaVideo {
    String type;
    String media;
    Optional<String> thumbnail;
    Optional<String> cover;
    Optional<Integer> start_timestamp;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<Boolean> width;
    Optional<Boolean> height;
    Optional<Boolean> duration;
    Optional<Boolean> supports_streaming;
    Optional<Boolean> has_spoiler;
};

InputMediaVideo Parse(const Value& value, To<InputMediaVideo>);

}  // namespace tg
