#include <types/photo_size.hpp>
#include <types/user_profile_photos.hpp>

#include "common.hpp"

namespace tg {

UserProfilePhotos Parse(const Value& value, To<UserProfilePhotos>) {
    UserProfilePhotos obj{};
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    obj.photos = ParseComplex<Array<Array<PhotoSize>>>(value["photos"]);
    return obj;
}

}  // namespace tg
