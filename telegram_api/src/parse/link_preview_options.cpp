#include <types/link_preview_options.hpp>

#include "common.hpp"

namespace tg {

LinkPreviewOptions Parse(const Value& value, To<LinkPreviewOptions>) {
    LinkPreviewOptions obj{};
    obj.is_disabled = ParseComplex<Optional<Boolean>>(value["is_disabled"]);
    obj.url = ParseComplex<Optional<String>>(value["url"]);
    obj.prefer_small_media =
        ParseComplex<Optional<Boolean>>(value["prefer_small_media"]);
    obj.prefer_large_media =
        ParseComplex<Optional<Boolean>>(value["prefer_large_media"]);
    obj.show_above_text =
        ParseComplex<Optional<Boolean>>(value["show_above_text"]);
    return obj;
}

}  // namespace tg
