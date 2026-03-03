#include <tg/types/paid_media.hpp>
#include <tg/types/paid_media_info.hpp>

#include "../internal/json_builder.hpp"
#include "common.hpp"

namespace tg {

PaidMediaInfo Parse(const Value& value, To<PaidMediaInfo>) {
    PaidMediaInfo obj{};
    obj.star_count = ParseComplex<Integer>(value["star_count"]);
    obj.paid_media = ParseComplex<Array<PaidMedia>>(value["paid_media"]);
    return obj;
}

void Serialize(const PaidMediaInfo& obj, ValueBuilder& builder) {
    internal::Put(builder, "star_count", obj.star_count);
    internal::Put(builder, "paid_media", obj.paid_media);
}

}  // namespace tg
