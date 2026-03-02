#include <tg/types/audio.hpp>
#include <tg/types/user_profile_audios.hpp>

#include "common.hpp"

namespace tg {

UserProfileAudios Parse(const Value& value, To<UserProfileAudios>) {
    UserProfileAudios obj{};
    obj.total_count = ParseComplex<Integer>(value["total_count"]);
    obj.audios = ParseComplex<Array<Audio>>(value["audios"]);
    return obj;
}

}  // namespace tg
