#include <tg/types/photo_size.hpp>
#include <tg/types/user_profile_photos.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UserProfilePhotos Parse(const Value& value, To<UserProfilePhotos>) {
    UserProfilePhotos obj{};
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    obj.photos = ParseComplex<Array<Array<PhotoSize>>>(value["photos"]);
    return obj;
}

void Serialize(const UserProfilePhotos& obj, ValueBuilder& builder) {
    internal::Put(builder, "total_count", obj.total_count);
    internal::Put(builder, "photos", obj.photos);
}

}  // namespace tg
