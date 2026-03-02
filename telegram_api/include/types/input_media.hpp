#pragma once

#include <types/common.hpp>
#include <types/input_media_animation.hpp>
#include <types/input_media_audio.hpp>
#include <types/input_media_document.hpp>
#include <types/input_media_photo.hpp>
#include <types/input_media_video.hpp>

namespace tg {

using InputMedia = OneOf<InputMediaAnimation, InputMediaDocument,
                         InputMediaAudio, InputMediaPhoto, InputMediaVideo>;

InputMedia Parse(const Value& value, To<InputMedia>);

}  // namespace tg
