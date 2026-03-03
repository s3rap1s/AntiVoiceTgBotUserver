#include <tg/types/input_media.hpp>
#include <tg/types/input_media_animation.hpp>
#include <tg/types/input_media_audio.hpp>
#include <tg/types/input_media_document.hpp>
#include <tg/types/input_media_photo.hpp>
#include <tg/types/input_media_video.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

InputMedia Parse(const Value& value, To<InputMedia>) {
    const auto type = ParseComplex<String>(value["type"]);
    if (type == "animation") return ParseComplex<InputMediaAnimation>(value);
    if (type == "document") return ParseComplex<InputMediaDocument>(value);
    if (type == "audio") return ParseComplex<InputMediaAudio>(value);
    if (type == "photo") return ParseComplex<InputMediaPhoto>(value);
    if (type == "video") return ParseComplex<InputMediaVideo>(value);
    throw ParseException("Unknown InputMedia type: " + type);
}

void Serialize(const InputMedia& obj, ValueBuilder& builder) { internal::Set(builder, obj); }

}  // namespace tg
