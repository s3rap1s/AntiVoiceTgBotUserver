#include <tg/types/audio.hpp>
#include <tg/types/user_profile_audios.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

UserProfileAudios Parse(const Value& value, To<UserProfileAudios>) {
    UserProfileAudios obj{};
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    obj.audios = ParseComplex<Array<Audio>>(value["audios"]);
    return obj;
}

void Serialize(const UserProfileAudios& obj, ValueBuilder& builder) {
    internal::Put(builder, "total_count", obj.total_count);
    internal::Put(builder, "audios", obj.audios);
}

}  // namespace tg
