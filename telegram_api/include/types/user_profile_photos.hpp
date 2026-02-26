#pragma once

#include "common.hpp"
#include "photo_size.hpp"

namespace tg {

struct UserProfilePhotos {
    Integer total_count;
    Array<Array<PhotoSize>> photos;
};

UserProfilePhotos Parse(const Value& value, To<UserProfilePhotos>);

}  // namespace tg
