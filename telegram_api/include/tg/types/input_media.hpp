#pragma once

#include <tg/types/common.hpp>
#include <tg/types/input_media_animation.hpp>
#include <tg/types/input_media_audio.hpp>
#include <tg/types/input_media_document.hpp>
#include <tg/types/input_media_photo.hpp>
#include <tg/types/input_media_video.hpp>

namespace tg {

using InputMedia = OneOf<InputMediaAnimation, InputMediaDocument,
                         InputMediaAudio, InputMediaPhoto, InputMediaVideo>;

InputMedia Parse(const Value& value, To<InputMedia>);

}  // namespace tg
