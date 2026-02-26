#pragma once

#include "audio.hpp"
#include "common.hpp"

namespace tg {

struct UserProfileAudios {
    Integer total_count;
    Array<Audio> audios;
};

UserProfileAudios Parse(const Value& value, To<UserProfileAudios>);

}  // namespace tg
