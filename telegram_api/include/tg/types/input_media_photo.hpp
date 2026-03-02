#pragma once

#include <tg/types/common.hpp>
#include <tg/types/message_entity.hpp>

namespace tg {

struct InputMediaPhoto {
    String type;
    String media;
    Optional<String> caption;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> caption_entities;
    Optional<Boolean> show_caption_above_media;
    Optional<Boolean> has_spoiler;
};

InputMediaPhoto Parse(const Value& value, To<InputMediaPhoto>);

}  // namespace tg
