#include <tg/types/paid_media_video.hpp>
#include <tg/types/video.hpp>

#include "common.hpp"

namespace tg {

PaidMediaVideo Parse(const Value& value, To<PaidMediaVideo>) {
    PaidMediaVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.video = ParseComplex<Video>(value["video"]);
    return obj;
}

}  // namespace tg
