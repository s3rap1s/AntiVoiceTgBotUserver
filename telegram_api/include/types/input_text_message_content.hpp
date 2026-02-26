#pragma once

#include "common.hpp"
#include "link_preview_options.hpp"
#include "message_entity.hpp"

namespace tg {

struct InputTextMessageContent {
    String message_text;
    Optional<String> parse_mode;
    Optional<Array<MessageEntity>> entities;
    Optional<LinkPreviewOptions> link_preview_options;
};

InputTextMessageContent Parse(const Value& value, To<InputTextMessageContent>);

}  // namespace tg
