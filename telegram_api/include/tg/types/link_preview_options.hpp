#pragma once

#include <tg/types/common.hpp>

namespace tg {

struct LinkPreviewOptions {
    Optional<Boolean> is_disabled;
    Optional<String> url;
    Optional<Boolean> prefer_small_media;
    Optional<Boolean> prefer_large_media;
    Optional<Boolean> show_above_text;
};

LinkPreviewOptions Parse(const Value& value, To<LinkPreviewOptions>);

}  // namespace tg
