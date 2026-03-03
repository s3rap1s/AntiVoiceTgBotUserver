#include <tg/types/paid_media_video.hpp>
#include <tg/types/video.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PaidMediaVideo Parse(const Value& value, To<PaidMediaVideo>) {
    PaidMediaVideo obj{};
    obj.type = ParseComplex<String>(value["type"]);
    obj.video = ParseComplex<Video>(value["video"]);
    return obj;
}

void Serialize(const PaidMediaVideo& obj, ValueBuilder& builder) {
    internal::Put(builder, "type", obj.type);
    internal::Put(builder, "video", obj.video);
}

}  // namespace tg
